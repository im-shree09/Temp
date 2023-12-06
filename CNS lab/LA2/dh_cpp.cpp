#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <chrono>


using namespace std;

long long int mod_pow(long long int base, long long int exponent, long long int mod) {
    long long int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

bool is_prime(long long int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

vector<long long int> generate_prime_numbers(long long int lower, long long int upper) {
    vector<long long int> primes;
    for (long long int num = lower; num < upper; num++) {
        if (is_prime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

int main() {
    cout<<"________________________________________________________________________________\n";
    cout<<"Lets Explore the Cyber security  -- Verifying Deffie Helman Key Exchange Algorithm Working ...  \n";

    cout<<"\n________________________________________________________________________________\n";
    this_thread::sleep_for(chrono::seconds(3));
     cout << "Generating prime numbers list .....:" << endl;
     this_thread::sleep_for(chrono::seconds(3));
    long long int lower_limit = 1;
    long long int upper_limit = 10000;

    vector<long long int> prime_numbers = generate_prime_numbers(lower_limit, upper_limit);

    
    for (size_t i = 0; i < prime_numbers.size(); i+=3) {
        cout << i + 1 << ": " << prime_numbers[i] << "\t"<<i + 2 << ": " << prime_numbers[i+1]<<"\t"<<i + 3 << ": " << prime_numbers[i+2]<<endl;
    }

    long long int prime_choice;
    cout << "Choose one prime number from the above  list (Choose Index No ):" << endl;
    cin >> prime_choice;
    prime_choice--;

    if (prime_choice < 0 || prime_choice >= prime_numbers.size()) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    long long int selected_prime = prime_numbers[prime_choice];

  this_thread::sleep_for(chrono::seconds(3));
     cout << "Generating primitive root values  list .....:" << endl;
     this_thread::sleep_for(chrono::seconds(3));
    vector<long long int> primitive_roots;
    for (long long int g = 2; g < 100; g++) {
        bool is_primitive_root = true;
        for (long long int i = 1; i < selected_prime - 1; i++) {
            if (mod_pow(g, i, selected_prime) == 1) {
                is_primitive_root = false;
                break;
            }
        }
        if (is_primitive_root) {
            primitive_roots.push_back(g);
        }
    }

   
    for (size_t i = 0; i < primitive_roots.size(); i++) {
        cout << i + 1 << ": " << primitive_roots[i] << endl;
    }

    long long int root_choice;
     cout << "Choose one primitive root from the above list (Choose Index No ):" << endl;
    cin >> root_choice;
    root_choice--;

    if (root_choice < 0 || root_choice >= primitive_roots.size()) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    long long int selected_root = primitive_roots[root_choice];

    long long int private_key_node1 = 10;
    long long int private_key_node2 = 5;

    long long int public_key_node1 = mod_pow(selected_root, private_key_node1, selected_prime);
    long long int public_key_node2 = mod_pow(selected_root, private_key_node2, selected_prime);

    cout << "\nPublic keys have been generated for Node 1 and Node 2." << endl;
    cout << "Public Key for Node 1: " << public_key_node1 << endl;
    cout << "Public Key for Node 2: " << public_key_node2 << endl;

    long long int shared_secret_node1 = mod_pow(public_key_node2, private_key_node1, selected_prime);
    long long int shared_secret_node2 = mod_pow(public_key_node1, private_key_node2, selected_prime);

    if (shared_secret_node1 == shared_secret_node2) {
        cout << "\nShared secret keys match! Diffie-Hellman key exchange successful." << endl;
        cout << "Shared Secret Key: " << shared_secret_node1 << endl;
    } else {
        cout << "\nShared secret keys do not match. Diffie-Hellman key exchange failed." << endl;
    }

    return 0;
}
