#include <iostream>
#include <string>
using namespace std;

struct Document
{
    string name;
    string date;
};
void bubbleSort(Document arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].date < arr[j + 1].date)
            {
                // Swap arr[j] and arr[j+1]
                Document temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    Document documents[] = {
        {"Document A", "2023-11-22"},
        {"Document B", "2023-12-01"},
        {"Document C", "2023-10-15"},
        {"Document D", "2024-01-01"}};

    int n = sizeof(documents) / sizeof(documents[0]);
    // Sort documents by date in descending order
    bubbleSort(documents, n);

    // Print the sorted documents
    for (int i = 0; i < n; i++)
    {
        cout << documents[i].name << " (" << documents[i].date << ")" << endl;
    }

    return 0;
}