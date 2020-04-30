/*    @file image.cpp
      @author <-- Fill in your name here -->
      @date <-- Fill this in -->
*/
// Example of generating and saving a PNG image.
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <QImage>
#include <QPixmap>
#include <QFile>
using namespace std;

class myComplex {
public:
  myComplex();
  myComplex(double in_real);
  myComplex(double in_real, double in_imaginary);

  void setReal(const double in_real);
  void setImaginary(const double in_imaginary);
  void setComplex(const double in_real, const double in_imaginary);

  double getReal() const;
  double getImaginary() const;
  double getMagnitude() const;
  double getAngle() const;

  void displayPolar() const;
  string display() const;

  myComplex conjugate();

  myComplex operator+ (const myComplex& right);
  myComplex operator- (const myComplex& right);
  myComplex operator* (const myComplex& right);
  myComplex operator/ (const myComplex& right);

  bool operator== (const myComplex& right);
  bool operator!= (const myComplex& right);


  friend ostream & operator<<( ostream& output,const myComplex &thing );
  friend istream & operator>>( istream &input, myComplex &thing );

private:
  double real;
  double imaginary;
};

// The fn we are creating the fractal of.
// f(x) = x^3 - 1
// Const reference for speed.
myComplex f(myComplex& a) {
    return a*a*a - 1;
    //return (a*a*a + 1)/(a*a);
}

// The derivitive of the above function.
// f(x) = 3 * x^2
// Const reference for speed.
myComplex df(myComplex& a){
    return a*a*3.0;
    //return (a*a*a - 2 )/(a*a*a);
}

// Global variable so we can see what the resulting point was.
// Useful ONLY if you need to know the root for colorig purposes.
// Alternatively newton could send back a struct.
static myComplex prev_one;

// Performs newton's estimation given a Complex starting point,
// maximum itterations, and a delta limit for how close it needs to
// be until it stops.
// Assumes f(Complex) and df(Complex) are defined.
unsigned newton(myComplex cur, unsigned int max_steps, double limit){
  prev_one = myComplex(1000,1000);
  unsigned steps = 0;
  while((cur - prev_one).getMagnitude() > limit && steps < max_steps){
    steps++;
    prev_one = cur;
    cur =  cur - f(cur)/df(cur);
    //cur = cur.subtraction(f(cur).division(df(cur)));
  }
  return steps;
}

int main(int argc, char* argv[]){
    // We accept 3 command-line paramters, filename, x and y
    // If no paramters are given, it will save a 800x600 image
    // to image.png

    string filename = "c:\\temp\\image.png";
    if(argc >= 2){
        filename = argv[1];
    }

    // Default Image size
    int width  = 800;
    int height = 600;

    if(argc >= 3){  // Width was given
        width = atoi(argv[2]);
    }
    if(argc >= 4){  // Height was given
        height = atoi(argv[3]);
    }

    // The image will be from -100 to +100 in both axes and scaled to
    // fit the requested image size.
    double urr = 100.0; // UpperRightReal (x)
    double uri = 100.0; // UpperRightImaginary (y)

    double llr = -100.0;
    double lli = -100.0;

    double dx = (urr-llr) / (double)width;
    double dy = (uri-lli) / (double)height;

    // Sample complex number math
    //complex<double> A(5.,5.), B(5.,5.);
    //cout << A - B << endl;

    // Setup the image in Qt
    QImage img(width, height, QImage::Format_RGB32);

    // Fill background with white
    img.fill(QColor(Qt::white).rgb());

    // Build image one pixel at a time.
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            // Calculate where in the complex plane this point is
            double real = static_cast<double>(x * dx + llr);
            double imaginary = static_cast<double>(y * dy * -1 + uri);
            // Now real and complex will be x and y from -100 to +100
            unsigned steps = newton(myComplex(real,imaginary), 200, 0.00001);


            unsigned char brightness = steps * 7 % 256;
            int red = 0;
            int blue = 0;
            int green = 0;
            if((prev_one - myComplex(-0.5, 0.866)).getMagnitude() < 0.5){
               // Red
                red = brightness;
                blue = 0;
                green = 0;
            }else if((prev_one - myComplex(1, 0)).getMagnitude() < 1){
                // Green
                red = 0;
                green = brightness;
                blue = 0;
            }else{
                // Blue
                red = 0;
                green = 0;
                blue = brightness;
            }
            img.setPixel(x, y, qRgb((int)red, // RED
                                    (int)green, // GREEN
                                    (int)blue)); // BLUE
        }
    }
    // save the image
    cout << "Saving: " << filename << " Width: " << width;
    cout << " Height: " << height << endl;
    // Saves the image
    QFile file(filename.c_str());
    img.save(file.fileName());

    // This requires imagemagick. It works on Windows
    // You will need to change imdisplay to display on Mac or Linux
    string display_it = "imdisplay " + filename;
    system(display_it.c_str());

    return 0;
}

static const double eq_delta = 0.0001;

  myComplex::myComplex(){
    real = 0.0;
    imaginary = 0.0;
  }

  myComplex::myComplex(double in_real){
    setComplex(in_real, 0.0);
  }

  myComplex::myComplex(double in_real, double in_imaginary){
    setComplex(in_real, in_imaginary);
  }

  void myComplex::setReal(const double in_real){
    real = in_real;
  }

  void myComplex::setImaginary(const double in_imaginary){
    imaginary = in_imaginary;
  }

  void myComplex::setComplex(const double in_real, const double in_imaginary){
    setReal(in_real);
    setImaginary(in_imaginary);
  }

  double myComplex::getReal() const {
    return real;
  }

  double myComplex::getImaginary() const {
    return imaginary;
  }

  double myComplex::getMagnitude() const {
    return hypot(real, imaginary);
  }

  double myComplex::getAngle() const {
    //if(real == 0 && imaginary == 0) return 0;
    //return atan( imaginary/real)*180.0/3.1415927;
    return atan2( imaginary,real)*180.0/3.1415927;
  }

  void myComplex::displayPolar() const {
    cout << getMagnitude();
    cout << "@ "  << getAngle() << endl;
  }

  string myComplex::display() const{
    stringstream retval;
    retval << "(" << real << " + " << imaginary << "i)";
    return retval.str();
  }

  myComplex myComplex::operator+ (const myComplex& right){

  }

  myComplex myComplex::operator- (const myComplex& right){
      myComplex retval;

      retval.real = real - right.real;
      retval.imaginary = imaginary - right.imaginary;

      return retval;
  }

  myComplex myComplex::operator* (const myComplex& right){
      myComplex retval;

      retval.real     = real*right.real       - imaginary*right.imaginary;
      retval.imaginary  = imaginary * right.real  + real * right.imaginary;

      return retval;
  }

  myComplex myComplex::operator/ (const myComplex& right){
      myComplex retval;
      double denom = right.real*right.real + right.imaginary*right.imaginary;

      retval.real    = (real*right.real + imaginary*right.imaginary)/denom;
      retval.imaginary = (imaginary*right.real - real*right.imaginary)/denom;

      return retval;
  }

  myComplex myComplex::conjugate(){
    return myComplex(real, 0-imaginary);
  }

  bool myComplex::operator== (const myComplex& right){
    double diff_real = abs(real - right.real);
    double diff_im = abs(imaginary - right.imaginary);

    return diff_real < eq_delta && diff_im < eq_delta;
  }

  bool myComplex::operator!= (const myComplex& right){
    return !(*this == right);
  }

ostream& operator<<( ostream& output, const myComplex &thing ){
  output << thing.display();
  return output;
}

istream& operator>>( istream &input, myComplex &thing ){
  cout << "Enter Real Part: ";
  input >> thing.real;
  cout << "Enter Imaginary Part: ";
  input >> thing.imaginary;
  return input;
}
