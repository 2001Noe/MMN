#include<iostream>
#include<conio.h>
using namespace std;
int rotate=0;
void menu();
class ADMIN{
	private:
		string plan;
		float price;
		float pfees;
		float cfees;
		string type[6]={"Heavyweight		Unlimited(over100kg)","Light-HeavyWeight	100kg",
			"Middleweight		90kg","Light-Middleweight	81kg","Lightweight	  	73kg",
			"Flyweight		66kg"};
	public:
		void getPlan(){
			cout<<"Set Training Plan\n";
			getline(cin,plan);
			cout<<"Set Fees for plan\n";
			cin>>price;
			cin.ignore();
		}
		void getFees(){
			cout<<"Set fees for private tuition per hour\n";
			cin>>pfees;
			cin.ignore();
			cout<<"Set competition fees\n";
			cin>>cfees;
			cin.ignore();
		}
		void showWeight(){
			cout<<"Categories"<<"\t"<<"	Upper Weight limit(kg)\n";
			for(int i=0;i<6;i++){
				cout<<i+1<<". "<<type[i]<<endl;
			}
		}		
		string rPlan(){
			return plan;
		}
		float rPrice(){
			return price;
		}
			int rPfees(){
			return pfees;
		}
		int rCfees(){
			return cfees;
		}
}; ADMIN A[4];
class CUSTOMER:public ADMIN{
	private:
		string savePlan;
		string saveComp;
		string saveTui;
		string take;
		string join;
		int choosePlan;
		int cPlan=0;
		int weightReturn=1;
		float savePrice;
		float saveComFees=0;
		float saveTuiFees=0;
		int com;
		int hours;
		float total;
	public:
		string name;
		void getName(){
			cout<<"Enter Name: ";
			getline(cin,name);
			ChoosePlan();
			Competition();
			cout<<"Do you want to take private tuition?\n(yes/no)\n";
			cin>>take;
			cin.ignore();
			Tuition(take);
			TotalCharges();
		}
		int ChoosePlan(){
			for(int i=0;i<3;i++){
				cout<<i+1<<". "<<A[i].rPlan()<<"\t"<<A[i].rPrice()<<endl;
			}
			cout<<"Choose Plan(1-3)\n";
			cin>>choosePlan;
			cin.ignore();
			switch (choosePlan){
				case 1:
					savePlan=A[choosePlan-1].rPlan();
					savePrice=A[choosePlan-1].rPrice();
					cPlan=1;
					return cPlan;
					break;
				case 2:
					savePlan=A[choosePlan-1].rPlan();
					savePrice=A[choosePlan-1].rPrice();
					cPlan=2;
					return cPlan;
					break;
				case 3:
					savePlan=A[choosePlan-1].rPlan();
					savePrice=A[choosePlan-1].rPrice();
					cPlan=3;
					return cPlan;
					break;
				default:
					cout<<"Invalid Choice!\n";
					ChoosePlan();
			}
		}
		void Tuition(string m){
			if(m=="yes"){
				cout<<"How many hours?\n";
				cin>>hours;
				cin.ignore();
				if(hours>=5){
					cout<<"Exceed limit!\n";
					Tuition(take);
				}
				else{
					saveTui="Take Tuition.\n";
					saveTuiFees=hours*A[0].rPfees();
				}
			}
			else{
				saveTui="Don't take tuition.\n";
				cout<<saveTui;
			}
		}
		int ChooseWeight(){
			int weight;
			ADMIN::showWeight();
			cout<<"Enter your weight: ";
			cin>>weight;
			cin.ignore();
			if(weight>100){
				saveComp="Heavyweight Competitions\n";
			}
			else if (weight==100){
				saveComp="Light Heavyweight Competitions\n";
			}
			else if(weight<100 && weight>=90){
				saveComp="Middleweight Competitions\n";
			}
			else if(weight<90 && weight>=81){
				saveComp="Light Middleweight Competitions\n";
			}
			else if(weight<81 && weight>=73){
				saveComp="Lightweight Competitions\n";
			}
			else if(weight<73 && weight>=66){
				saveComp="Flyweight Competitions\n";
			}
			else if(weight<66){
				saveComp="Can't join competition for lower weight.\n";
				weightReturn=0;
			}
			return weightReturn;
		}
		void Competition(){
			if(cPlan==1){
				saveComp="Can't join competition as you choose beginner.\n";
				cout<<saveComp;
			}
			else if (cPlan==2||cPlan==3){
				cout<<"Join Competition(yes/no)\n";
				cin>>join;
				cin.ignore();
				if(join=="no"){
					saveComp="Don't join competition.\n";
					cout<<saveComp;
				}
				else if(join=="yes"){
					ChooseWeight();
					if(weightReturn==0){
						cout<<saveComp;
					}
					else if(weightReturn==1){
						cout<<saveComp;
						cout<<"How many competitions?\n";
						cin>>com;
						cin.ignore();
						saveComFees=com*A[0].rCfees();	
					}
				}
			}		
		}
	void TotalCharges(){
		total=savePrice+saveComFees+saveTuiFees;
		cout<<"Total Charges: "<<total<<endl<<endl;
	}	
	void CusInfo(){
		cout<<"Name: "<<name<<endl<<"Choice Plan: "<<savePlan<<endl
		<<"Plan charges: "<<savePrice<<endl<<"Tuition: "<<saveTui
		<<"Tuition Fees: "<<saveTuiFees<<" for "<<hours<<"-hour.\n"
		<<"Competition: "<<saveComp<<"Competition Fees: "<<saveComFees
		<<" for "<<com<<"-competition.\n"<<"Total Charges: "<<total<<"\n"<<endl;
	}
}; CUSTOMER Cus[10];
void heapify(CUSTOMER arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l].name > arr[largest].name)
        largest = l;
 
    if (r < n && arr[r].name > arr[largest].name)
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(CUSTOMER arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void admin(){
	system("CLS");
	int adminChoice;
	cout<<"Choose:\n1.Insert Training Plans\n2.View Plan\n3.Customer Information\n4.Menu\n";
	cin>>adminChoice;
	cin.ignore();
	switch(adminChoice){
		case 1:
			for(int i=0;i<3;i++){
				A[i].getPlan();
			}
			A[0].getFees();
			getch();
			admin();
			break;
		case 2:
			for(int i=0;i<3;i++){
				cout<<"Plan"<<i+1<<"."<<A[i].rPlan()<<"  \t"<<"Price: "<<A[i].rPrice()<<endl;
			}
			cout<<"Tuiton fees per hour: "<<A[0].rPfees()<<endl;
			cout<<"Competition charges per competition: "<<A[0].rCfees()<<endl;
			getch();
			admin();
			break;
		case 3:
			heapSort(Cus, rotate);
			for(int i=0;i<rotate;i++){
				Cus[i].CusInfo();
			}
			getch();
			admin();
			break;
		default:
			menu();
	}
}
void customer(){
	system("CLS");
	int cusChoice;
	cout<<"1.Choose Plan\n2.View Plan and Weight for competitons\n3.View Customer Information\n4.Menu\n";
	cin>>cusChoice;
	cin.ignore();
	switch (cusChoice){
		case 1:
			Cus[rotate].getName();
			rotate++;
			Cus[rotate-1].CusInfo();
			getch();
			customer();
			break;
		case 2:
			cout<<"Training Plans\n";
			for(int i=0;i<3;i++){
				cout<<"Plan"<<i+1<<"."<<A[i].rPlan()<<"  \t"<<"Price: "<<A[i].rPrice()<<endl;
			}
			cout<<"Tuiton fees per hour: "<<A[0].rPfees()<<endl;
			cout<<"Competition charges per competition: "<<A[0].rCfees()<<endl<<endl;
			A[0].showWeight();
			getch();
			customer();
			break;
		case 3:
			heapSort(Cus, rotate);
			for(int i=0;i<rotate;i++){
				Cus[i].CusInfo();
			}
			getch();	
			customer();
			break;
		default:
			menu();
	}
}
void menu(){
	int userChoice;
	system("CLS");
	cout<<"Choose User:\n1.Admin\n2.Customer\n3.Guest\n";
	cin>>userChoice;
	cin.ignore();
	switch(userChoice){
		case 1:
			admin();
			break;
		case 2:
			customer();
			break;
		case 3:
			cout<<"Guest can only view Training Plan.\n";
			for(int i=0;i<3;i++){
				cout<<"Plan"<<i+1<<"."<<A[i].rPlan()<<"	\t"<<"Price:"<<A[i].rPrice()<<endl;
			}
			cout<<"Tuiton fees per hour: "<<A[0].rPfees()<<endl;
			cout<<"Competition charges per competition: "<<A[0].rCfees()<<endl;
			getch();
			menu();
			break;
	}	
}
int main(){
	menu();
	return 0;
}
