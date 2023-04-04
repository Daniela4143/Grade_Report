#include<iostream>
#include<cstring>
#include<istream>
using namespace std;

class Stnode{
	protected:  //才可被繼承 
	int no;
	int math;
	char name[21]; //有一個保留字元 
	Stnode *ptr;  
	
	public:
	Stnode(){
		no=0;
		math=0;
	}
	void writeno(int t){
		no=t;
	}  
	void writemath(int q){
		math=q;
	}
	void writename(char j[21]){			
	    strncpy(name, j, 21);
	}
	void writeptr(Stnode* next){
		ptr=next;
	}
	int readno(){
		return no;
	}
	int readmath(){
		return math;
	}
	char* readname(){
		return name;
	} 
	Stnode* readptr(){
		return ptr;
	}
};
class MENU{		//將menu改成物件 
	public:
		void menu(){
			cout<<"(1).新增學生資料"<<endl
			<<"(2).刪除學生資料"<<endl
			<<"(3).列印串列資料"<<endl	
			<<"(4).列印成績單"<<endl
			<<"(5).離開"<<endl
			<<"請輸入選擇項目?";
		}
};
class CS : public Stnode{
	protected:
	int cs;
	int oo;
	CS *cptr; 
	int ctg;  //總分 
	
	public:
		void writecs(int k){
			cs=k;
		}
		void writeoo(int c){
			oo=c;
		}
		void writecptr(CS* cnext){
			cptr=cnext;
		}
		int readcs(){
			return cs;
		}
		int readoo(){
			return oo;
		}
		CS* readcptr(){
			return cptr;
		}
		int readctg(){
			return math + oo + cs;
		}
};
class PE : public Stnode{
	protected:
	int pe;
	PE *pptr;
	int ptg;
	
	public:
		void writepe(int p){
			pe=p;
		}
		void writepptr(PE* pnext){
			pptr=pnext;
		}
		int readpe(){
			return pe;
		}
		PE* readpptr(){
			return pptr;
		}
		int readptg(){
			return math + pe;
		}
};

int main() {
	CS *head=NULL;
	CS *p;
	CS *f;
	CS *n;
	
	PE *head1=NULL;
	PE *p1;
	PE *f1;
	PE *n1;
	
	MENU m;
	
	int a=0; //計算資料筆數 (cs)
	int a1=0; //計算資料筆數 (pe)
	
	int tno; //Stnode的資料 (cs)
	int qmath;
	char jname[21];
	CS* next;
	int tno1; //Stnode的資料 (pe)
	int qmath1;
	char jname1[21];
	PE* next1;

	int kcs;//CS的特殊資料 
	int coo;
	int kpe;//PE的特殊資料
	
	int dno; //欲刪除資料的座號(cs)
	int dno1; //欲刪除資料的座號(pe)

	cout<<"歡迎您使用學生資料系統"<<endl
		<<"◎提醒您:若未依照屏幕指示(括弧中敘述)輸入，系統可能會出現錯誤。"<<endl
		<<"------------------------------------"<<endl;
		 
	int nu; //menu選項 
	m.menu();
	while(cin>>nu){
		while(nu<1 || nu>5){
			cout<<"<系統錯誤>無此選項，請重新輸入選擇項目:"<<endl;
			cin>>nu; 
		} 
		
		if(nu==1){ //新增資料 
			int select;
			cout<<endl<<"請選擇要新增之學生資料的科系:資科系請輸入0，體育系請輸入1:";
			cin>>select;
			while(select!=0 && select!=1){
				cout<<endl<<"無此選項，請重新輸入";
				cin>>select;
			}
			if(select==0){
				cout<<endl<<"<資科系>新增學生資料執行中"<<endl;
				n=new CS;
				do{
					cout<<"請輸入學生座號:";
					double dtno;
					cin>>dtno;
					tno=dtno;
					while(tno<=0 || dtno-tno!=0){
						cout<<"不符合規定，請重新輸入座號:"; 
						cin>>dtno;
						tno=dtno;
					}
				
					if(a > 0){ //座號相同，無法輸入 
						p=head;
						for(int i=1; i<a; i++){
							if(p->readno()==tno){     
								break; 
		 					}
	 						p=p->readcptr();
	 					}
		 				if(p->readno()==tno){
	 						cout<<endl<<"此座號已存在,無法輸入(若要新增此筆資料，請先至選項2刪除舊的資料)"<<endl
							 	<<"自行回到選單"<<endl<<endl;
		 					break;
	 					}
					}
					n->writeno(tno);
					
					cout<<endl<<"請輸入學生計概成績(整數,0~100):";
					double dkcs;
					cin>>dkcs;
					kcs=dkcs;
					while(kcs<0 || kcs>100 || dkcs-kcs!=0){
						cout<<"不符合規定，請重新輸入成績:"; 
						cin>>dkcs;
						kcs=dkcs;
					}
					n->writecs(kcs); 
				
					cout<<endl<<"請輸入學生程式成績(整數,0~100):";
					double dcoo;
					cin>>dcoo;
					coo=dcoo;
					while(coo<0 || coo>100 || dcoo-coo!=0){
						cout<<"不符合規定，請重新輸入成績:"; 
						cin>>dcoo;
						coo=dcoo;
					}
					n->writeoo(coo); 
					
					cout<<endl<<"請輸入學生數學成績(整數,0~100):";
					double dqmath;
					cin>>dqmath;
					qmath=dqmath;
					while(qmath<0 ||qmath>100 || dqmath-qmath!=0){
						cout<<"不符合規定，請重新輸入成績:"; 
						cin>>dqmath;
						qmath=dqmath;
					}
					n->writemath(qmath); 
					
					cout<<endl<<"請用英文輸入學生名字(含空格最多20個字母):";
					cin.get( );
					cin.getline(jname, 21);
					n->writename(jname);
					cout<<endl;
					a++;
		
					if(a==1){    //head指向儲存第一筆資料的空間 
						head=n;
						p=head;
						f=head;
					}else{
						CS *s=head;
						if(head->readno()>n->readno()){ //前端插入法:當新資料<第一筆資料時執行 
							p=n;
							p->writecptr(head);
							head=p;
							f=p;
							p=p->readcptr();
						}else{
							while(s->readcptr()&&(s->readcptr()->readno())<(n->readno())){ //找出新資料要插入的位置 (s->no)<(n->no)<((s->next)->no)
								s=s->readcptr();	
							}
							if(s->readcptr()==NULL){
								f=s;	//後端插入法 
								f->writecptr(n);
								p->writecptr(f->readcptr());
								p=p->readcptr();
							}else{
								f=s;  //將f,p兩指標分別指到要連接新資料的前後空間 
								p=s->readcptr();
								n->writecptr(p); //中間插入法 
								p=n;
								p->writecptr(n->readcptr());
								f->writecptr(n);
								f=f->readcptr();
							}	
						}
					}
			
					p=head;
					for(int i=1; i<a;i++){
						p=p->readcptr();	
					}
	
					cout<<"是否繼續輸入下一筆資料?(1為是/0為否)";
					int c;
					cin>>c;
					cout<<endl;	
				
					while(c!=0 && c!=1){
						cout<<"無此選項，請重新輸入";
						cin>>c;
					}
					if(c==1){
						n=new CS;
						p->writecptr(NULL);
					}else if(c==0){
						p->writecptr(NULL);
						p=p->readcptr();
						n=NULL;
					}
				}while(p);
				m.menu();
			}else if (select==1){
				cout<<endl<<"<體育系>新增學生資料執行中"<<endl;
				n1=new PE;
				do{
					cout<<"請輸入學生座號:";
					double dtno1;
					cin>>dtno1;
					tno1=dtno1;
					while(tno1<=0 || dtno1-tno1!=0){
						cout<<"不符合規定，請重新輸入座號:"; 
						cin>>dtno1;
						tno1=dtno1;
					}
				
					if(a1 > 0){ //座號相同，無法輸入 
						p1=head1;
						for(int i=1; i<a1; i++){
							if(p1->readno()==tno1){     
								break; 
		 					}
		 					p1=p1->readpptr();
	 					}
	 					if(p1->readno()==tno1){
	 						cout<<endl<<"此座號已存在,無法輸入(若要新增此筆資料，請先至選項2刪除舊的資料)"<<endl
							 	<<"自行回到選單"<<endl<<endl;
	 						break;
	 					}
					}
					n1->writeno(tno1);
					
					cout<<endl<<"請輸入學生體育成績(整數,0~100):";
					double dkpe;
					cin>>dkpe;
					kpe=dkpe;
					while(kpe<0 || kpe>100 || dkpe-kpe!=0){
						cout<<"不符合規定，請重新輸入成績:"; 
						cin>>dkpe;
						kpe=dkpe;
					}
					n1->writepe(kpe); 
				
					cout<<endl<<"請輸入學生數學成績(整數,0~100):";
					double dqmath1;
					cin>>dqmath1;
					qmath1=dqmath1;
					while(qmath1<0 ||qmath1>100 || dqmath1-qmath1!=0){
						cout<<"不符合規定，請重新輸入成績:"; 
						cin>>dqmath1;
						qmath1=dqmath1;
					}
					n1->writemath(qmath1); 
				
					cout<<endl<<"請用英文輸入學生名字(含空格最多20個字母):";
					cin.get( );
					cin.getline(jname1, 21);
					n1->writename(jname1);
					cout<<endl;
					a1++;
		
					if(a1==1){    //head指向儲存第一筆資料的空間 
						head1=n1;
						p1=head1;
						f1=head1;
					}else{
						PE *s1=head1;
						if(head1->readno()>n1->readno()){ //前端插入法:當新資料<第一筆資料時執行 
							p1=n1;
							p1->writepptr(head1);
							head1=p1;
							f1=p1;
							p1=p1->readpptr();
						}else{
							while(s1->readpptr()&&(s1->readpptr()->readno())<(n1->readno())){ //找出新資料要插入的位置 (s->no)<(n->no)<((s->next)->no)
								s1=s1->readpptr();	
							}
							if(s1->readpptr()==NULL){
								f1=s1;	//後端插入法 
								f1->writepptr(n1);
								p1->writepptr(f1->readpptr());
								p1=p1->readpptr();
							}else{
								f1=s1;  //將f,p兩指標分別指到要連接新資料的前後空間 
								p1=s1->readpptr();
								n1->writepptr(p1); //中間插入法 
								p1=n1;
								p1->writepptr(n1->readpptr());
								f1->writepptr(n1);
								f1=f1->readpptr();
							}	
						}
					}
		
					p1=head1;
					for(int i=1; i<a1;i++){
						p1=p1->readpptr();
					}
	
					cout<<"是否繼續輸入下一筆資料?(1為是/0為否)";
					int c1;
					cin>>c1;
					cout<<endl;	
					
					while(c1!=0 && c1!=1){
						cout<<"無此選項，請重新輸入";
						cin>>c1;
					}
					if(c1==1){
						n1=new PE;
						p1->writepptr(NULL);
					}else if(c1==0){
						p1->writepptr(NULL);
						p1=p1->readpptr();
						n1=NULL;
					}
				}while(p1);	
				m.menu();
			}
		}
		
		else if(nu==2){ //刪除資料 
			int select;
			cout<<endl<<"請選擇要刪除之學生資料的科系:資科系請輸入0，體育系請輸入1:";
			cin>>select;
			while(select!=0 && select!=1){
				cout<<endl<<"無此選項，請重新輸入";
				cin>>select;
			}
			if(select==0){
				cout<<endl<<"<資科系>刪除學生資料執行中"<<endl;
				int y;
				do{
					if(a==0){
						cout<<"該筆資料不存在，無法刪除" 
							<<endl<<"自行回到選單"<<endl<<endl;
					}else{
						cout<<"請輸入欲刪除的學生資料之座號:";
						cin>>dno;
						p=head;
						f=head;
						for(int i=1; i<a; i++){
							if(p->readno()==dno){     
								break; 
		 					}
		 					f=p;
		 					p=p->readcptr();
		 				}
		 				if(p->readno()==dno){
		 					if(a==1){ //只有一筆資料時的刪除方法 	
		 						head=NULL;
		 						p=new CS; //讓p不為0 
							 }else if(p!=head){ //欲刪除資料不在head時 
							 	f->writecptr(p->readcptr());
			 					p=f;
			 					p->writecptr(f->readcptr());
			 					if(p->readcptr()){ //超過兩筆資料時 
			 						p=p->readcptr();	
								}
							 }else if (p==head){ //欲刪除資料在head時 
							 	head=p->readcptr();
							 }
			 				cout<<endl<<"該筆資料已成功刪除"<<endl<<endl;  
			 				a--;
			 			}else{
			 				cout<<endl<<"該筆資料不存在，無法刪除"<<endl<<endl; 
						}
					
						cout<<"是否需要繼續刪除資料?(1為是/0為否)"<<endl;
						cin>>y;
						while(y!=0 && y!=1){
							cout<<"無此選項，請重新輸入";
							cin>>y;
						}
						if(y==0){
							cout<<endl;
							break;
						}
						if(a==0){
							cout<<"該筆資料不存在，無法刪除" 
							<<endl<<"自行回到選單"<<endl<<endl;
						}
					}	
				}while(a);
				m.menu();
			}else if(select==1){
				cout<<endl<<"<體育系>刪除學生資料執行中"<<endl;
				int y1;
				do{
					if(a1==0){
						cout<<"該筆資料不存在，無法刪除" 
							<<endl<<"自行回到選單"<<endl<<endl;
					}else{
						cout<<"請輸入欲刪除的學生資料之座號:";
						cin>>dno1;
						p1=head1;
						f1=head1;
						for(int i=1; i<a1; i++){
							if(p1->readno()==dno1){     
								break; 
		 					}
		 					f1=p1;
		 					p1=p1->readpptr();
		 				}
		 				if(p1->readno()==dno1){
		 					if(a1==1){ //只有一筆資料時的刪除方法 	
		 						head1=NULL;
		 						p1=new PE; //讓p不為0 
							 }else if(p1!=head1){ //欲刪除資料不在head時 
							 	f1->writepptr(p1->readpptr());
			 					p1=f1;
			 					p1->writepptr(f1->readpptr());
			 					if(p1->readpptr()){ //超過兩筆資料時 
			 						p1=p1->readpptr();	
								}
							 }else if (p1==head1){ //欲刪除資料在head時 
							 	head1=p1->readpptr();
							 }
			 				cout<<endl<<"該筆資料已成功刪除"<<endl<<endl;  
			 				a1--;
			 			}else{
			 				cout<<endl<<"該筆資料不存在，無法刪除"<<endl<<endl; 
						}
					
						cout<<"是否需要繼續刪除資料?(1為是/0為否)"<<endl;
						cin>>y1;
						while(y1!=0 && y1!=1){
							cout<<"無此選項，請重新輸入";
							cin>>y1;
						}
						if(y1==0){
							cout<<endl;
							break;
						}
						if(a1==0){
							cout<<"該筆資料不存在，無法刪除" 
							<<endl<<"自行回到選單"<<endl<<endl;
						}
					}	
				}while(a1);
				m.menu();				
			}
			
		}
		
		else if(nu==3){ //列印資料 
			int select;
			cout<<endl<<"請選擇要列印之學生資料的科系:資科系請輸入0，體育系請輸入1:";
			cin>>select;
			while(select!=0 && select!=1){
				cout<<endl<<"無此選項，請重新輸入";
				cin>>select;
			}
			if(select==0){
				cout<<endl<<"<資科系>列印串列資料執行中"<<endl;
				p=head;
				cout<<endl;
				cout<<"head->"; 
				for(int i=0; i<a; i++) { 
					cout<<p->readno()<<"->"; 
					p=p->readcptr();
				}
				cout<<"||"<<endl<<endl;
				m.menu();
			}else if(select==1){
				cout<<endl<<"<體育系>列印串列資料執行中"<<endl;
				p1=head1;
				cout<<endl;
				cout<<"head->"; 
				for(int i=0; i<a1; i++) { 
					cout<<p1->readno()<<"->"; 
					p1=p1->readpptr();
				}
				cout<<"||"<<endl<<endl;
				m.menu();
			}
		}
		
		else if(nu==4){ //列印成績單 
			int select;
			cout<<endl<<"請選擇要列印之學生成績單的科系:資科系請輸入0，體育系請輸入1:"<<endl;
			cin>>select;
			while(select!=0 && select!=1){
				cout<<endl<<"無此選項，請重新輸入";
				cin>>select;
			}
			if(select==0){
				while(a==0){
					cout<<"無學生資料，無法輸出成績單。"<<endl<<endl; 
					break;
				}
				CS csg[a];
				p=head;
				for(int i=0; i<a; i++) { 
					csg[i]=*p;		//取值	
					p=p->readcptr();
				}
				for(int i=0; i<a-1; i++) {
					for(int j=i+1; j<a; j++){
						if(csg[i].readctg() < csg[j].readctg()){
							CS t;
							t=csg[i];
							csg[i]=csg[j];
							csg[j]=t;
						}
					}
				}
				if(a!=0){
					cout<<"<資科系>列印學生成績單(依名次排序):"<<endl; 
				}
				for(int i=0; i<a;i++){
		//			cout<<"第"<<i+1<<"名:"<<endl;
					cout<<"姓名:"<<csg[i].readname()<<endl;
					cout<<"座號:"<<csg[i].readno()<<endl;
					cout<<"總成績:"<<csg[i].readctg()<<endl;
					cout<<"數學成績:"<<csg[i].readmath()<<endl;
					cout<<"計概成績:"<<csg[i].readcs()<<endl;
					cout<<"物件導向程設成績:"<<csg[i].readoo()<<endl<<endl;
				} 
				cout<<"回到選單"<<endl<<endl; 
				m.menu(); 
			}else if(select==1){
				while(a1==0){
					cout<<"無學生資料，無法輸出成績單。"<<endl<<endl; 
					break;
				}
				PE peg[a1];
				p1=head1;
				for(int i=0; i<a1; i++) { 
					peg[i]=*p1; 
					p1=p1->readpptr();
				}
				for(int i=0; i<a1-1; i++) {
					for(int j=i+1; j<a1; j++){
						if(peg[i].readptg() < peg[j].readptg()){
							PE t;
							t=peg[i];
							peg[i]=peg[j];
							peg[j]=t;
						}
					}
				}
				if(a1!=0){
					cout<<"<體育系>列印學生成績單(依名次排序):"<<endl; 
				}
				for(int i=0; i<a1;i++){
		//			cout<<"第"<<i+1<<"名:"<<endl; 
					cout<<"姓名:"<<peg[i].readname()<<endl;
					cout<<"座號:"<<peg[i].readno()<<endl;
					cout<<"總成績:"<<peg[i].readptg()<<endl;
					cout<<"數學成績:"<<peg[i].readmath()<<endl;
					cout<<"體育成績:"<<peg[i].readpe()<<endl<<endl;
				} 
				cout<<"回到選單"<<endl<<endl; 
				m.menu();
			}
		}else if(nu==5){ //離開 
			cout<<"系統結束"<<endl 
				<<"------------------------------------"
				<<endl<<"感謝您的使用"<<endl 
				<<"祝 身體健康 平安喜樂";
			break; 
		}
	}	 
}  
