#include <iostream>
#include "json.h"
#include "j_stream.h"
#include <limits>
#include <fstream>

//using namespace std;


int main(){
    int n, h, m, k;
    std::cin >> n >> h >> m >> k;

    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
        std::cin >> arr[i][0] >> arr[i][1];
    }

    int best_result = n;
    int best_t = 0;

    int * bad_trains = new int[n]; for(int i = 0; i < n; i++) bad_trains[i] = 0;

    for (int t = 0; t < m/2; t++){
        int result = n;
        for (int train = 0; train < n; train++)
            if ((arr[train][0]*m + arr[train][1] - t) % (k + m/2) < m/2) result--;
        if (result < best_result) {
            best_result = result;
            best_t = t;

            for(int i = 0; i < n; i++) bad_trains[i] = 0;
            for (int train = 0; train < n; train++)
                if ((arr[train][0]*m + arr[train][1] - t) % (k + m/2) >= m/2) bad_trains[train] = 1;
        }
    }
    std::cout << best_result << " " << best_t << std::endl;
    for(int i = 0; i < n; i++)
        if (bad_trains[i] == 1) std::cout << i+1;
    return 0;


}


//    int recursive(int * arr, int n, int deep, int k, int sum_so_far){
//    int beau = 0;
//    for (int i = 0; i < n;i++){
//        if (arr[i] != 1){
//            if (deep == n){
//                if ((sum_so_far + (i+1)*deep) % k == 0) return 1;
//                return 0;
//            }
//            arr[i] = 1;
//            beau += recursive(arr, n, deep+1, k, sum_so_far + (i+1)*deep);
//            arr[i] = 0;
//        }
//    }
//    return beau;
//}
//
//int main()
//{
//    int n, k;
//    std::cin >> n >> k;
//
//    int * arr = new int[n];
//    for (int i = 0; i < n; i++) arr[i] = 0;
//
//    std::cout << recursive(arr, n, 1, k, 0);
//    return 0;
//
//}



//    ifstream file("json_test.txt");
//    Json k;
//    try{
//        file >> k;
//        cout << k << endl;
//    }catch (parcer_exception& e){
//        cout << e.what() << " " << e.where();
//    }
//
////    J_array k;
////    try{
////    while(true){
////            cin >> k;
////            cout << k << endl;
////    }
////    }catch (parcer_exception& e){
////        cout << e.what() << " " << e.where();
////    }
//    return 0;
//}
