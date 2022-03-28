#include <iostream>
#include <vector>

using namespace std;
#define MAX_MOVEMENT 4

vector<vector<int> > farm;

long int Sum(vector<int> row_fields) {
     long int sum = 0;
    for (int i = 0; i < row_fields.size(); i++)
    sum += row_fields[i];
    return sum;
}

vector<long int> sum_the_rows(int m) {
        vector<long int> row_sums;
        long int sum = 0;
    for(int i = 0; i < m; i++){
            sum = Sum(farm[i]);
            row_sums.push_back(sum);
            sum = 0;
        }
        return row_sums;
}

int find_max_element_in_row(int& row,int m,vector<long int> row_sums){
        int max_row = 0;
        for(int i = 0; i < m; i++) {
            if (row_sums[i] > max_row) {
                max_row = row_sums[i];
                row = i;
            }
        }
        return max_row;
}

int find_max_element_in_col(int n,int m,int& column){
        long int sum = 0;
        int maxColumn = 0;
    for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++){
                sum += farm[i][j];
            }
            if(sum > maxColumn){
                maxColumn = sum;
                column = j;
            }
            sum = 0;
        }
        return maxColumn;
}

long int solve(int m, int n){
    long int harvest = 0;
    int max_row;
    int maxColumn = 0;
    int row = 0;
    int column = 0;

    for(int move = 0; move < MAX_MOVEMENT; move++) {
        vector<long int> row_sums;

        row_sums = sum_the_rows(m);
        max_row = find_max_element_in_row(row,m,row_sums);
        maxColumn = find_max_element_in_col(n,m,column);
        
        
        if(maxColumn > max_row) {
            harvest += maxColumn;
            for(int i = 0; i < m; i++){
                farm[i][column] = 0;
            }
        }
        else {
            harvest += max_row;
            for(int j = 0; j < n; j++){
                farm[row][j] = 0;
            }
        }
        row = 0;
        column = 0;
        maxColumn = 0;
        max_row = 0;
    }
    return harvest;
}

vector < vector < int > > get_harvests(int m,int n){
    int product;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> product;
            farm[i][j] = product;
        }    
    }
    return farm;
}

int main() {
    int m, n;
    cin>>m>> n;
    farm = vector < vector < int > > (m, vector<int>(n));
    farm = get_harvests(m,n); 
    cout<<solve(m, n);
    return 0;
    cout << "Hello there! I'm unreachable!" << endl;
} 