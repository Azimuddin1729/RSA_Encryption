#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define int long long
//RSA message encryption 

//first we will check if the number is prime or not
bool isPrime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

//now a generator function to generate a random prime number between minimum and maximum
ll generatePrime(ll minimum, ll maximum){
    ll n;
    while(1){
        n = rand()%(maximum-minimum+1)+minimum;
        if(isPrime(n)) return n;
    }
}


//now we will find the inverse of a number first we will make binary exponentiation function
ll power(ll a,ll n,ll m){
    ll res = 1;
    while(n){
        if(n%2){
            res = (res*a)%m;
            n--;
        }
        else{
            a = (a*a)%m;
            n/=2;
        }
    }
    return res;
}

ll modInverse(ll e,ll phi){
    //check if e and phi are coprime
    if(__gcd(e,phi)!=1) return -1;
    return power(e,phi-1,phi);
}

//now we will generate the public and private keys


signed main(){
    srand(time(0));
    ll p = generatePrime(1000,5000);
    ll q = generatePrime(1000,5000);
    while(p==q) q = generatePrime(1000,5000); //to make sure p and q are not same

    ll n = p*q;
    ll phi = (p-1)*(q-1);

    ll e = generatePrime(3,phi);

    ll d = modInverse(e,phi);
    
    cout<<"Public key: "<<e<<" "<<endl;

    cout<<"Private key: "<<d<<" "<<endl;

    string message= "Cryptography is fun!";
    cout<<"Original message: "<<message<<endl;

    string encryptedMessage = "";
    for(ll i=0;i<message.size();i++){
        ll x = message[i];
        ll y = power(x,e,n);
        encryptedMessage+=to_string(y);
        encryptedMessage+=" ";
    }
    cout<<"Encrypted message: "<<encryptedMessage<<endl;

    return 0;

}
