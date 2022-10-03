#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main(){
    /* List of variables */
    char con = 'y';
    bool giveChange = false;
    double moneyIn = 0;
    double moneyInOriginal = 0;
    int moneyInTimesHundred = moneyIn*100;
    int quarterChange;
    int dimeChange;
    int nickelChange;

    // Number of coins
    int numberOfNickels = 25;
    int numberOfDimes = 25;
    int numberOfQuarters = 25;
    int numberOfOnes = 0;
    int numberOfFives = 0;
    
    // Coin values
    double nickel = 0.05;
    double dime = 0.10;
    double quarter = 0.25;
    double one = 100;
    double five = 500;
    int numberFive = 5;

    // Input values
    float price;
    int priceByFive;

    cout << "Welcome to the vending machine change maker program" << endl;
    cout << "Change maker initialized." << endl;

    // Printing the contents of the stock
    cout << "Stock contains:" << endl;
    cout << "\t" << numberOfNickels << " nickels" << endl;
    cout << "\t" << numberOfDimes << " dimes" << endl;
    cout << "\t" << numberOfQuarters << " quarters" << endl;
    cout << "\t" << numberOfOnes << " ones" << endl;
    cout << "\t" << numberOfFives << " fives" << endl;
    while(con == 'y'){
        cout << "Enter the purchase price (xx.xx): ";
        cin >> price;
        double priceOriginal = price;
        cout << "Menu for deposits: \n\t'n' - Deposit a nickel\n\t'd' - Deposit a dime\n\t'q' - Deposit a quarter\n\t'o' - Deposit a one dollar bill\n\t'f' - Deposit a five dollar bill\n\t'c' - Cancel the purchase" << endl;
        int priceTimesHundred = price * 100;
        int centBreaker = double(priceTimesHundred);
        priceByFive = priceTimesHundred % numberFive;

        while(priceByFive != 0 || price <= 0){
            cout << "Illegal price: Must be a non-negative multiple 5 cents.\nEnter the purchase price (xx.xx): ";
            cin >> price;
            double priceOriginal = price;
            int priceTimesHundred = price*100;
            priceByFive = priceTimesHundred % numberFive;
        }

        bool isChar = false;
        while(priceTimesHundred > 0|| !isChar){
            
            cout << "Indicate your deposit: ";
            char deposit;
            cin >> deposit;
            switch(deposit){
            case 'n':
                cout << "Nickel deposited\n";
                moneyIn += 5;
                moneyInOriginal += 5;
                isChar = true;
                price -= nickel;
                numberOfNickels += 1;
                priceTimesHundred = price*100;
                centBreaker = int(priceTimesHundred);
                price = round(price*100)/100;
                break;
            case 'd':
                cout << "Dime deposited\n";
                moneyIn += 10;
                moneyInOriginal += 10;
                isChar = true;
                price -= dime;
                numberOfDimes += 1;
                priceTimesHundred = price*100;
                centBreaker =  int(priceTimesHundred);
                price = round(price*100)/100;
                break;
            case 'q':
                cout << "Quarter deposited\n";
                moneyIn += 25;
                moneyInOriginal += 25;
                isChar = true;
                price -= quarter;
                numberOfQuarters += 1;
                priceTimesHundred = price*100;
                centBreaker = int(priceTimesHundred);
                price = round(price*100)/100;
                break;
            case 'o':
                cout << "One dollar deposited\n";
                moneyIn+= 100;
                moneyInOriginal += 100;
                isChar = true;
                //price -= 1;
                numberOfOnes += 1;
                priceTimesHundred -= 100;
                centBreaker = int(priceTimesHundred);
                break;
            case 'f':
                cout << "Five dollar deposited\n";
                moneyIn += 500;
                moneyInOriginal += 500;
                isChar = true;
                price -= 5;
                numberOfFives += 1;
                priceTimesHundred = price*100;
                centBreaker = int(priceTimesHundred);
                break;
            case 'c':
                isChar = true;
                giveChange = true;
                
                quarterChange = 0;
                dimeChange = 0;
                nickelChange = 0;
                moneyInOriginal;
                
                // Greedy Algorithm
                if((numberOfQuarters > 0 || numberOfDimes > 0 || numberOfNickels > 0) && giveChange == true){
                    for(numberOfQuarters; numberOfQuarters > 0 && (moneyIn)>= 25; numberOfQuarters--){
                        if((moneyIn-25) >= 0){
                            quarterChange++;
                            moneyIn-=25;
                        }
                    }
                    for(numberOfDimes; numberOfDimes > 0 && (moneyIn)>= 10; numberOfDimes--){
                        if((moneyIn-10) >= 0){
                            dimeChange++;
                            moneyIn-=10;
                        } 
                    }
                    for(numberOfNickels; numberOfNickels > 0 && (moneyIn)>= 5; numberOfNickels--){
                        if((moneyIn-5) >= 0){
                            nickelChange++;
                            moneyIn-=5;
                        }
                    }
                }
                if(numberOfQuarters == 0 && numberOfDimes == 0 && numberOfNickels == 0){
                    cout << "Machine is out of change." << endl;
                    cout << "See store manager for remaining refund." << endl;
                    cout << "Amount due is: " << moneyInOriginal/100-(double(quarterChange)*0.25+double(dimeChange)*0.10+double(nickelChange)*0.05) << " dollars and " << centBreaker % 100 << " cents" << endl;
                    cout << "No change due." << endl;
                    cout << "Do you want to continue (y/n): ";
                    cin >> con;
                }   
                
                // Prompting the user to take change
                cout << "Please take the change below." << endl;
                cout << "\t" << quarterChange << " quarters" << endl;
                cout << "\t" << dimeChange << " dimes" << endl;
                cout << "\t" << nickelChange << " nickels" << endl;

                cout << "Stock contains:" << endl;
                cout << "\t" << numberOfNickels << " nickels" << endl;
                cout << "\t" << numberOfDimes << " dimes" << endl;
                cout << "\t" << numberOfQuarters << " quarters" << endl;
                cout << "\t" << numberOfOnes << " ones" << endl;
                cout << "\t" << numberOfFives << " fives" << endl;

                giveChange = true;

                // Resetting the temporary variables for the next loop
                price = 0;
                priceTimesHundred = 0;
                moneyIn = 0;
                moneyInOriginal = 0;
                quarterChange = 0;
                dimeChange = 0;
                nickelChange = 0;
                giveChange = false;
                
                // Asking if user wants to continue
                cout << "Do you want to continue (y/n): ";
                cin >> con;
                break;

            // Displays illegal selection
            default:
                cout << "Illegal selection: " << deposit << endl;

            }

            // Payment due display if there's payment due
            if(price > 0){
                cout << "Payment due is: " << int(price);if(int(price) == 1){cout << " dollar";}else{cout << " dollars";}cout << " and " << centBreaker % 100 << " cents" << endl;
            }

            // Change for if more money is put in than needed
            // Uses Greedy Algorithm
            quarterChange = 0;
            dimeChange = 0;
            nickelChange = 0;
            while(priceTimesHundred < 0){
                cout << numberOfQuarters << endl;
                for(numberOfQuarters; numberOfQuarters > 0; numberOfQuarters--){
                    if(priceTimesHundred-25 <= 0){
                        quarterChange++;
                        priceTimesHundred+=25;
                    }
                    
                }
                for(numberOfDimes; numberOfDimes > 0; numberOfDimes--){
                    if(priceTimesHundred-10 <= 0){
                        dimeChange++;
                        priceTimesHundred-=10;
                        
                    }
                }
                for(numberOfNickels; numberOfNickels > 0; numberOfNickels--){
                    if(priceTimesHundred-5 <= 0){
                        nickelChange++;
                        priceTimesHundred-=5;
                    }
                }
                cout << priceTimesHundred << endl;

                // Prompting the user to take change
                cout << "Please take the change below." << endl;
                cout << "\t" << quarterChange << " quarters" << endl;
                cout << "\t" << dimeChange << " dimes" << endl;
                cout << "\t" << nickelChange << " nickels" << endl;
                giveChange = true;

                // Resetting the temporary variables for the next loop
                price = 0;
                priceTimesHundred = 0;
                moneyIn = 0;
                moneyInOriginal = 0;
                quarterChange = 0;
                dimeChange = 0;
                nickelChange = 0;
                giveChange = false;
                
                // Asking if user wants to continue
                cout << "Do you want to continue (y/n): ";
                cin >> con;
                break;
            }
        }
    }
    return 0;
}
