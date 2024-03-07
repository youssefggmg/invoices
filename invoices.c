#include <stdio.h>
#include <string.h>


float calculateTotal(float prices[], int numArticles) {
    float total = 0;
    for (int i = 0; i < numArticles; i++) {
        total += prices[i];
    }
    return total;
}

float calculateVAT(float totalHT, float vatRate) {
    return totalHT * (vatRate / 100);
}

float calculateTotalTTC(float totalHT, float vatAmount) {
    return totalHT + vatAmount;
}

int main() {
    char customerName[100];
    float articlePrices[3];
    float totalHT, vatRate, vatAmount, totalTTC;
    char paymentMethod[50];

    printf("Enter customer name: ");
    scanf(" %[^\n]", customerName); 
    
    printf("Enter the prices of 3 articles: \n");
    for (int i = 0; i < 3; i++) {
        printf("Article %d: ", i+1);
        scanf("%f", &articlePrices[i]);
    }

    printf("Enter the total HT: ");
    scanf("%f", &totalHT);

    printf("Enter the VAT rate: ");
    scanf("%f", &vatRate);

    printf("Enter the payment method: ");
    scanf("%s", paymentMethod);
    float totalAmount = calculateTotal(articlePrices, 3);

    vatAmount = calculateVAT(totalHT, vatRate);

    totalTTC = calculateTotalTTC(totalHT, vatAmount);
    printf("\n===== Invoice =====\n");
    printf("Customer: %s\n", customerName);
    printf("Articles:\n");
    for (int i = 0; i < 3; i++) {
        printf("- Article %d: %.2f\n", i + 1, articlePrices[i]);
    }
    printf("Total HT: %.2f\n", totalHT);
    printf("VAT rate: %.2f%%\n", vatRate);
    printf("VAT amount: %.2f\n", vatAmount);
    printf("Total TTC: %.2f\n", totalTTC);
    printf("Payment Method: %s\n", paymentMethod);
    return 0;
}
