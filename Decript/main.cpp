#include <iostream>

using namespace std;

string encript(string sample){
    string encrypted_sample = sample;
    for(unsigned i = 0; i < sample.length(); i++){

        if (isupper(sample[i]))
            encrypted_sample[i] += 2;

        if (ispunct(sample[i]))
            encrypted_sample[i] *= 2;

        if (islower(sample[i]))
            encrypted_sample[i] = (encrypted_sample[i]%10)+30;

        if (encrypted_sample[i] < 32)
            encrypted_sample[i] += 50;

    }

    for(unsigned i = 0; i < sample.length(); i++){
        encrypted_sample[i] += 1;
        if (encrypted_sample[i]>126)
            encrypted_sample[i] = 65+rand()%4;

    }

    return(encrypted_sample);

}

string decript(string sample){
    string encrypted_sample = sample;

    for(unsigned i = 0; i < sample.length(); i++){
        encrypted_sample[i] -= 1;
        if (encrypted_sample[i]>126)
            cout << encrypted_sample[i];
            //encrypted_sample[i] = 65+rand()%4;

    }
    cout << encrypted_sample << endl;

    for(unsigned i = 0; i < sample.length(); i++){

        if (isupper(sample[i]))
            encrypted_sample[i] -= 2;

        if (ispunct(sample[i]))
            encrypted_sample[i] /= 2;

        if (islower(sample[i]))
            encrypted_sample[i] = (encrypted_sample[i]%10)-30;

        if (encrypted_sample[i] < 32)
            encrypted_sample[i] -= 50;

    }



    return(encrypted_sample);

}


int main()
{
    cout << encript("Hello freind.") << endl;
    return 0;
}
