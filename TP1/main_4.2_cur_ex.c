#include <stdio.h>
/*
This exercise can be more correct by calculating the ratio exchange of
EUR_GBP by using these ratio USD_EUR and USD_GBP.
In this program, I keep three of them separatedly to be same with your example
(You asked to give inputs for 3 raio)
*/

// Currency exchange ratio
double USD_EUR = 0.85; // 1 USD = 0.85 EUR
double USD_GBP = 0.76; // 1 USD = 0.76 GBP
double EUR_GBP = 0.89; // 1 EUR = 0.89 GBP

// Convert USD to EUR
double usd_to_eur(double amount) {
    return amount * USD_EUR;
}

// Convert USD to GBP
double usd_to_gbp(double amount) {
    return amount * USD_GBP;
}

// Convert EUR to USD
double eur_to_usd(double amount) {
    return amount / USD_EUR;
}

// Convert EUR to GBP
double eur_to_gbp(double amount) {
    return amount * EUR_GBP;
}

// Convert GBP to USD
double gbp_to_usd(double amount) {
    return amount / USD_GBP;
}

// Convert GBP to EUR
double gbp_to_eur(double amount) {
    return amount / EUR_GBP;
}

int main() {
    char input, output;
    double amount, result;
    
    // Input of own exchange rates
    printf("Known exchange rates\n\n");
    printf("$ to € = %lf\n", USD_EUR);
    printf("$ to £ = %lf\n",USD_GBP);
    printf("€ to £ = %lf\n",EUR_GBP);
    
    // Ask the user if they want to use the predefined balances or input new ones
    printf("Do you wish to use the above known rates (press 1) or to rather insert your own (press 2)?\n");
    scanf(" %c", &input);
    
    // Input new exchange rates
    if (input == '2') {
        printf("You have selected to provide your own rates\n");
        printf("Please provide the exchange rate US to EURO (multiplied by 100.000000)\n");
        scanf("%lf", &USD_EUR);
        USD_EUR /= 100;
        printf("Please provide the exchange rate US to POUND (multiplied by 100.000000)\n");
        scanf("%lf", &USD_GBP);
        USD_GBP /= 100;
        printf("Please provide the exchange rate EURO to POUND (multiplied by 100.000000)\n");
        scanf("%lf", &EUR_GBP);
        EUR_GBP /= 100;
        printf("New exchange rates\n\n");
        printf("$ to € = %lf\n", USD_EUR);
        printf("$ to £ = %lf\n",USD_GBP);
        printf("€ to £ = %lf\n",EUR_GBP);        
    }
    else {
        printf("You have selected to use the pre-set rates\n");
    }  
    
    // Choose input currency
    printf("\nChoose the type of the input currency.\n");
    printf("Press 1 for $\n");
    printf("Press 2 for €\n");
    printf("Press 3 for £\n");
    scanf(" %c", &input);

    // Input amount to be exchanged
    printf("\nChoose the input amount.\n");
    scanf("%lf", &amount);

    // Choose output currency
    printf("\nChoose the type of the output currency.\n");
    printf("Press 1 for $\n");
    printf("Press 2 for €\n");
    printf("Press 3 for £\n");
    scanf(" %c", &output);

    // Use if else to list all possible cases
    if (input == '1' && output == '1') {
        // convert USD to USD
        result = amount;
        printf("Converted amount: %.2lf USD = %.2lf USD\n", amount, result);
    } 
    else if (input == '1' && output == '2') {
        // convert USD to EUR
        result = usd_to_eur(amount);
        printf("Converted amount: %.2lf USD = %.2lf EUR\n", amount, result);
    } 
    else if (input == '1' && output == '3') {
        // convert USD to GBP
        result = usd_to_gbp(amount);
        printf("Converted amount: %.2lf USD = %.2lf GBP\n", amount, result);
    }
    else if (input == '2' && output == '1') {
        // convert EUR to USD
        result = eur_to_usd(amount);
        printf("Converted amount: %.2lf EUR = %.2lf USD\n", amount, result);
    } 
    else if (input == '2' && output == '2') {
        // convert EUR to EUR
        result = amount;
        printf("Converted amount: %.2lf EUR = $%.2lf EUR\n", amount, result);
    } 
    else if (input == '2' && output == '3') {
        // convert EUR to GBP
        result = eur_to_gbp(amount);
        printf("Converted amount: %.2lf EUR = $%.2lf GBP\n", amount, result);
    } 
    else if (input == '3' && output == '1') {
        // convert GBP to USD
        result = gbp_to_usd(amount);
        printf("Converted amount: %.2lf GBP = %.2lf USD\n", amount, result);
    } 
    else if (input == '3' && output == '2') {
        // convert GBP to EUR
        result = gbp_to_eur(amount);
        printf("Converted amount: %.2lf GBP = %.2lf EUR\n", amount, result);
    }    
    else if (input == '3' && output == '3') {
        // convert GBP to GBP
        result = amount;
        printf("Converted amount: %.2lf GBP = %.2lf GBP\n", amount, result);
    }    
    else {
        printf("Invalid input or output currency code.\n");
    }  
    return 0;
}