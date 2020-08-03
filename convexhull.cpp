/*Nama Muhammad Ayyub Abdurrahman
  NIM 13518076
  IF 2110 Strategi Algoritma
  COnvex-Hull Problem with Brute-FOrce Algrithm */

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <ratio>
#include <chrono>
// #include <graphics.h>

using namespace std;
using namespace std::chrono;

typedef struct convex {
    /* data */
    int x;
    int y;
} TITIK;

int main(){
    /* KAMUS */
    int n,a,b,c,i,j,k; //jumlah titik, garis, dan counter
    TITIK daftar_titik[1000], daftar_penyusun[1000],sementara;
    bool posisi1, posisi2, posisi3, start;
    clock_t time;

    /*ALGORITMA*/
    // input jumlah titik
    cout << "Masukkan N: "; 
    cin >> n;
    cout << " " << endl;
    // input titik dan menyimpan ke list
    /* for (i = 1; i <= n; i++){
        cout << "Masukkan data titik ke-" << i << " : ";
        cout << "Masukkan X: "; 
        cin >> daftar_titik[i].x;
        cout << "Masukkan Y: "; 
        cin >> daftar_titik[i].y;
        cout << " " << endl;
    } */

    //random titik
    for (i = 1; i <= n; i++){
    	daftar_titik[i].x = rand()%100;
    	if (rand()%2 == 1){
    		daftar_titik[i].x *= -1;
		}
		daftar_titik[i].y = rand()%100;
    	if (rand()%2 == 1){
    		daftar_titik[i].y *= -1;
		}
    }
    cout << "[";
    for (i = 1; i < n; i++){
        cout << "(" << daftar_titik[i].x << "," << daftar_titik[i].y << "),";
    }
    cout << "(" << daftar_titik[n].x << "," << daftar_titik[n].y << ")" << "]" << endl;
    // waktu mulai dihitung
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    // mencari titik convex hull pertama dan menyimpan ke list
    sementara = daftar_titik[1];
    for (i = 1; i <= n; i++){
       if (daftar_titik[i].x <= sementara.x){
           sementara = daftar_titik[i];
       }
    }
    k = 1;
    daftar_penyusun[k] = sementara;
    // mencari titik penyusun convex hull berikutnya
    start = true;
    i = 1;
    while (start){
    	//cout << "titik 1: (" << daftar_penyusun[k].x << "," << daftar_penyusun[k].y << "), ";
    	//cout << "titik 2: (" << daftar_titik[i].x << "," << daftar_titik[i].y << "), " <<endl;
        if (!(((daftar_penyusun[k].x == daftar_titik[i].x) && (daftar_penyusun[k].y == daftar_titik[i].y)) || ((daftar_penyusun[k-1].x == daftar_titik[i].x) && (daftar_penyusun[k-1].y == daftar_titik[i].y)))){
            // garis diantara 2 titik yang dipilih
            a = daftar_penyusun[k].y - daftar_titik[i].y;
            b = daftar_titik[i].x - daftar_penyusun[k].x;
            c = ((daftar_titik[i].x * daftar_penyusun[k].y) - (daftar_titik[i].y * daftar_penyusun[k].x));
            j = 1; // counter titik uji
            posisi1 = false; // posisi dimana ax + by > c
            posisi2 = false; // posisi dimana ax + by < c
            posisi3 = false; // posisi dimana ax + by = c
            sementara = daftar_titik[i];
			//pengujian
            while ((j <= n) && ((posisi1 == false) || (posisi2 == false))){
            	if (!(((daftar_penyusun[k].x == daftar_titik[j].x) && (daftar_penyusun[k].y == daftar_titik[j].y)) || ((daftar_titik[j].x == daftar_titik[i].x) && (daftar_titik[j].y == daftar_titik[i].y)))){
            		if ((a*daftar_titik[j].x+b*daftar_titik[j].y == c) && (!(((daftar_penyusun[k].x == daftar_titik[j].x) && (daftar_penyusun[k].y == daftar_titik[j].y)) || ((daftar_penyusun[k-1].x == daftar_titik[j].x) && (daftar_penyusun[k-1].y == daftar_titik[j].y)))) && ((pow((daftar_penyusun[k].x-sementara.x),2) + pow((daftar_penyusun[k].y-sementara.y),2)) > (pow((daftar_penyusun[k].x-daftar_titik[j].x),2) + pow((daftar_penyusun[k].y-daftar_titik[j].y),2)))){
            				posisi3 = true;
	                    	//cout << "titik 3: (" << daftar_titik[j].x << "," << daftar_titik[j].y << ") terdeteksi segaris. melanjutkan pencarian " <<endl;
	                    	sementara = daftar_titik[j];
                	}
                	if (a*daftar_titik[j].x+b*daftar_titik[j].y > c){
                    	posisi1 = true;
                    	//cout << "titik 3: (" << daftar_titik[j].x << "," << daftar_titik[j].y << ") berada di posisi 1 " <<endl;
                	}
					if (a*daftar_titik[j].x+b*daftar_titik[j].y < c){
                   		posisi2 = true;
                		//cout << "titik 3: (" << daftar_titik[j].x << "," << daftar_titik[j].y << ") berada di posisi 2 " <<endl;
                	}
				}
                j++;
            }
            // pengujian sudah selesai
            if (posisi3 == false){
            	if (((posisi1 == false) || (posisi2 == false))){ // diasumsikan semua titik berada di posisi yang sama (posisi1 atau posisi2), sehingga titik dianggap penyusun convex hull
            		if ((daftar_penyusun[1].x == daftar_titik[i].x) && (daftar_penyusun[1].y == daftar_titik[i].y)){
						//cout << "titik 2 berhasil, pencarian selesai" <<endl;
	            		k++;
	            		daftar_penyusun[k] = daftar_titik[i];
		            	start = false;
					} else {
						//cout << "titik 2 berhasil, melanjutkan pencarian" <<endl;
						daftar_penyusun[k+1] = daftar_titik[i];
	                	k++;
	                	i = 1;
					}  
            	} else {
            		//cout << "titik 2 gagal, karena bukan penyusun convex hull" <<endl;
            		i++;
				}	
			} else {
				if (((posisi1 == false) || (posisi2 == false))){
					if ((daftar_penyusun[1].x == sementara.x) && (daftar_penyusun[1].y == sementara.y)){
						//cout << "titik 2 berhasil, pencarian selesai" <<endl;
	            		k++;
	            		daftar_penyusun[k] = sementara;
		            	start = false; 
					} else {
						//cout << "titik 2 berhasil, melanjutkan pencarian" <<endl;
						daftar_penyusun[k+1] = sementara;
	                	k++;
	                	i = 1;
					}  
				} else {
            		//cout << "titik 2.1 gagal, karena bukan penyusun convex hull" <<endl;
            		i++;
				}
			}
        } else {
        	//cout << "titik 2 gagal, karena sama dengan titik 1 atau garis sebelumnya" <<endl;
        	i++;
		}
    }
    //waktu selesai
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double, std::milli> time_span = t2 - t1;

    std::cout << "Dibutuhkan waktu " << time_span.count() << " milliseconds.";
    std::cout << std::endl;
    // mencetak titik-titik ke layar
    cout << "[";
    for (i = 1; i < k; i++){
        cout << "(" << daftar_penyusun[i].x << "," << daftar_penyusun[i].y << "),";
    }
    cout << "(" << daftar_penyusun[k].x << "," << daftar_penyusun[k].y << ")" << "]" << endl;

    //plotting dalam gambar 
    /* int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    for (i = 1; i < k; i++){
        line(daftar_penyusun[i].x,daftar_penyusun[i].y,daftar_penyusun[i+1].x,daftar_penyusun[i+1].y);
    }
    getch(); 
    closegraph(); 
    return 0;*/
}
