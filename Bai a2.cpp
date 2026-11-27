#include<iostream>
#include<string>
using namespace std;
class lichhoc{
	private:
		string malich,tenmon,malop,giangvien,phonghoc;
		int thu,tiet,sotiet;
		
	public:
		lichhoc(){
				malich="",tenmon="",malop="",giangvien="",phonghoc="",thu=0,tiet=0,sotiet=0;
		}
		void nhaplich(){
			cout<<"\nNhap ma lich hoc: ";
			getline(cin,malich);
			cout<<"\nnhap ten mon hoc: ";
			getline(cin,tenmon);
			cout<<"\nnhap ma lop: ";
			getline(cin,malop);
			cout<<"\ngiang vien: ";
			getline(cin,giangvien);
			cout<<"\nphong hoc: ";
			getline(cin,phonghoc);
			cout<<"\nnhap thu, tiet, sotiet: ";
			cin>>thu;
			cin.ignore(100,'\n');
			cin>>tiet;
			cin.ignore(100,'\n');
			cin>>sotiet;
			cin.ignore(100,'\n'); 
		}
		void inra(){
			cout<<malich<<"\t|"<<tenmon<<"\t|"<<malop<<"\t|"<<giangvien<<"\t|"<<phonghoc<<"\t|"<<thu<<"\t|"<<tiet<<"\t|"<<sotiet<<"\t|"<<endl;
		}
		void sua(){
			int n;
			cout<<"\n NHAP THONG TIN CAN SUA\n"<<"1. sua all"<<"\n2. sua malich"<<"\n3. sua ten mon"<<"\n4. ma lop va giang vien:"<<"\n5. sua thu,tiet,sotiet ";
			cin>>n;
			cin.ignore(100,'\n');
			if(n==1){
				nhaplich();
			}
			else if(n==2){
				getline(cin,malich);
			}
			else if(n==3){
			    getline(cin,tenmon);
			}
			else if(n==4){
				getline(cin,malop);
				getline(cin,giangvien);
			}
			else if(n==5){
				cin>>thu>>tiet>>sotiet;
			}
			else{
				cout<<"kh co lua chon nay";
			}	
					
		}
		string laymalich() {return malich;}
		string laytenmon() {return tenmon;}
		string laymalop() {return malop;}
		string laygiangvien() {return giangvien;}
		int laythu(){ return thu;}
		int laytiet(){return tiet;}
		int laysotiet(){return sotiet;}
};
class quanlydanhsach{
	private:
		lichhoc manglich[200];
		int soluong;
	public:
		quanlydanhsach(){
			soluong=0;
		}
		void nhapdanhsach(){
			int i=0;
			cout<<"\nso lich hoc muon nhap(1-200): ";
			cin>>soluong;
			cin.ignore(100,'\n');
			for(i=0;i<soluong;i++){
				cout<<"\n NHAP DANH SACH THU"<<i+1<<endl;
				manglich[i].nhaplich();
			}
		}
		void indanhsach(){
			int i=0;
			cout<<"\nMA LICH\t|"<<"TEN MON\t|"<<"MA LOP\t|"<<"GIANG VIEN\t|"<<"PHONG\t|"<<"TIET\t|"<<"THU TIET\t|"<<"SO TIET\t|";
			cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			for(i=0;i<soluong;i++){
				manglich[i].inra();
			}
		}
		void xapxep(){
			int i=0,j=0;
			lichhoc doi;
			for(i=0;i<soluong-1;i++){
				for(j=i+1;j<soluong;j++){
					if(manglich[i].laythu()>manglich[j].laythu() || manglich[i].laythu()>manglich[j].laythu()&&manglich[i].laytiet()>manglich[j].laytiet()){
						doi=manglich[i];
						manglich[i]=manglich[j];
						manglich[j]=doi;
					}
				}
			}
		}
		void timkiem(){
			int chon;
			int i; 
			cout<<"\nCHON CACH TIM\n1. tim theo ma lop\n2. tim theo ten mon\n";
			cin>>chon;
			cin.ignore(100,'\n');
			cout<<"\nNhap tu khoa muon tim: ";
			string tim;
			getline(cin,tim);
			int dem=0;
			for(i=0;i<soluong;i++){
				if(manglich[i].laymalop()==tim || manglich[i].laytenmon()==tim){
					manglich[i].inra();
					dem++;
				}
				}
				if(dem==0){
					cout<<"khong ton tai doi tuong nay!";
			}
		}
		void sualich(){
			int vitri;
			do{
			cout<<"\nChon vi tri can sua: ";
			cin>>vitri;
			cin.ignore(100,'\n');
	       }while(vitri<1 || vitri>soluong);
	       manglich[vitri-1].sua();
		}
		void themlich(){
			lichhoc moi;
			int i; 
			int vitri;
			cout<<"\n chon vi tri can them: ";
			cin>>vitri;
			cin.ignore(100,'\n');
			cout<<"thong tin lich moi them vao: ";
			moi.nhaplich();
			for(i=soluong;i>=vitri;i--){
				manglich[i]=manglich[i-1];
			}
			manglich[vitri-1]=moi;
			soluong++;
			cout<<"ok roi";
		}
		void xoalich(){
			int vitri;
			cout<<"chon vi tri muon xoa(1-"<<soluong<<" :";
			cin>>vitri;
			cin.ignore(100,'\n');
			for(int i=vitri-1;i<=soluong-2;i++){
				manglich[i]=manglich[i+1];
			}
			soluong--; 
		}
};
		int main(){
			quanlydanhsach ql;
			ql.nhapdanhsach();
			cout<<"\n CHON CAC THAO TAC\n";
			cout<<"\n 1. in danh sach hien tai\n 2. xap xep\n 3. tim kiem\n 4. sua\n 5. them\n 6.xoa\n7. Thoat ";
			int luachon;
			cin>>luachon;
			if(luachon==1){
				ql.indanhsach();
			}
			else if(luachon==2){
				ql.xapxep();
			}
			else if(luachon==3){
				ql.timkiem();
			}
			else if(luachon==4){
				ql.sualich();
			}
			else if(luachon==5){
				ql.xoalich();
			}
			else if(luachon==7){
				cout<<" Thoat ";
			}
			else {
				cout<<" lua chon khong hop le!";
			}
		}
