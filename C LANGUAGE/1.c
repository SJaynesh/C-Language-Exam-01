#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Products
{
    int product_id;
    char product_name[50];
    float price;
    int qty;
};

int main()
{

    int n, size, add = 0, dup = 0;
    int id;
    float sum = 0;
    float mul = 1;

    struct Products p1[100];
    do
    {
        printf("\n\n\n\t Inventory Management System \n");
        printf("01\tAdd a new product to the inventory\n");
        printf("02\tDisplay all products in the inventory\n");
        printf("03\tSearch for a product by ID or Name\n");
        printf("04\tUpdate product details by ID\n");
        printf("05\tDelete a product from the inventory by ID\n");
        printf("06\tCalculate and display the total value of inventory\n");
        printf("07\tExit\n");

        // printf("Enter number of products: ");
        // scanf("%d", &size);

        printf("\nEnter any choice\t: ");
        scanf("%d", &n);

        switch (n)
        {
        case 01:
            system("cls");

            printf("\n\tAdd All Products\n\n");
            printf("Enter Product Id\t:");
            scanf("%d", &p1[add].product_id);
            for (int i = 0; i <= add; i++)
            {
                for (int j = i + 1; j <= add; j++)
                {
                    if (p1[i].product_id == p1[j].product_id)
                    {
                        dup = j;
                        break;
                    }
                }
                if (dup != 0)
                    break;
            }
            if (dup == 0)
            {
                fflush(stdin);
                printf("Enter Product Name\t:");
                scanf("%[^\n]", &p1[add].product_name);
                printf("Enter Product Price\t:");
                scanf("%f", &p1[add].price);
                printf("Enter Product Qty\t:");
                scanf("%d", &p1[add].qty);

                system("cls");
            }
            else
            {
                printf("%d is duplicate ID", p1[dup].product_id);
            }
            add++;
            break;

        case 02:
            system("cls");
            printf("\n\tDisplay All Products\n\n");
            printf("ID\tName\tPrice\tQty\n");
            printf("--\t----\t-----\t---\n");
            for (int i = 0; i < add; i++)
            {
                printf("%d\t%s\t%0.2f\t%d\n", p1[i].product_id, p1[i].product_name, p1[i].price, p1[i].qty);
            }

            break;

        case 03:
            system("cls");
            printf("\n\tSearch any Products\n\n");
            printf("Enter product Id\t:");
            scanf("%d", &id);

            system("cls");
            printf("ID\tName\tPrice\tQty\n");
            printf("--\t----\t-----\t---\n");
            for (int i = 0; i < add; i++)
            {
                if (id == p1[i].product_id)
                    printf("%d\t%s\t%0.2f\t%d\n", p1[i].product_id, p1[i].product_name, p1[i].price, p1[i].qty);
            }

            break;
        case 04:
            // int id;
            system("cls");
            int p_id;
            char p_name[50];
            float price;
            int qty;
            printf("\n\tUpdate any Products\n\n");
            printf("Enter update product Id\t:");
            scanf("%d", &id);

            system("cls");

            // printf("\n\tPlease Enter Update Product\n\n");
            // printf("Enter Product Id\t:");
            // scanf("%d", &p_id);
            // printf("Enter Product Name\t:");
            // scanf("%[^\n]", &p_name);
            // printf("Enter Product Price\t:");
            // scanf("%f", &price);
            // printf("Enter Product Qty\t:");
            // scanf("%d", &qty);

            for (int i = 0; i < add; i++)
            {
                if (id == p1[i].product_id)
                {
                    printf("Enter Product Id\t:");
                    scanf("%d", &p1[i].product_id);
                    fflush(stdin);
                    printf("Enter Product Name\t:");
                    scanf("%[^\n]", &p1[i].product_name);
                    printf("Enter Product Price\t:");
                    scanf("%f", &p1[i].price);
                    printf("Enter Product Qty\t:");
                    scanf("%d", &p1[i].qty);
                }
            }

            break;
        case 05:
            // int id;
            int del;
            printf("\n\tDelete any Products\n\n");
            printf("Enter product Id\t:");
            scanf("%d", &id);

            printf("\nProduct Delete Successfully");

            for (int i = 0; i < add; i++)
            {
                if (id == p1[i].product_id)
                {
                    del = i;
                }
            }

            for (int i = del; i < add; i++)
            {
                p1[i].product_id = p1[i + 1].product_id;
                strcpy(p1[i].product_name, p1[i + 1].product_name);
                p1[i].qty = p1[i + 1].qty;
                p1[i].price = p1[i + 1].price;
            }
            add--;

            break;
        case 06:
            system("cls");
            printf("\n\tCalculate and display the total value of inventory\n\n");

            for (int i = 0; i < add; i++)
            {
                mul = p1[i].price * (float)p1[i].qty;
                sum += mul;
            }

            system("cls");
            printf("\tID\tName\tPrice\tQty\n");
            printf("\t--\t----\t-----\t---\n");
            for (int i = 0; i < add; i++)
            {
                printf("\t%d\t%s\t%0.2f\t%d\n", p1[i].product_id, p1[i].product_name, p1[i].price, p1[i].qty);
            }

            printf("\n\nTotal\t: %0.2f\n", sum);

            break;
        case 07:
            system("cls");
            printf("GOOD BY 👋👋");
            break;

        default:
            system("cls");
            printf("Invalid choice");
            break;
        }

    } while (n != 7);

    FILE *fp;

    fp = fopen("product.txt", "w");

    for (int i = 0; i < add; i++)
    {
        fprintf(fp, "ID %d\t: %d\n", i + 1, p1[i].product_id);
    }

    return 0;
}
