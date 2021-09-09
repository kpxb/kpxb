#include <iostream>
#include<stdio.h>
using namespace std;
class genshin{
	public:
		double gjl;//攻击力 
		double bl;
		double bjsh;
		double bjl;
		double shjc;
		double rwdj;
		double gwdj;
		double gwfyl;
		int ysjt;
		
		double getjbxx(double a,double b,double c,double d,double e,double f,double g,double h,int i){
			gjl=a;
			bl=b;
			bjsh=c;
			bjl=d;
			shjc=e;
			rwdj=f;
			gwdj=g;
			gwfyl=h;
			ysjt=i;
			return 0;
		}
};
class Buff:public genshin{
	public:
		void getwyBuff(double a){//有风套万叶buff情况 
			shjc=shjc+0.0004*a;
			gwfyl=gwfyl-0.4;
		}
		void getbntBuff(double a){//有宗室套班尼特buff情况 
		    gjl=gjl+1.46*a;
		}
			void getmnBuff(void){//有教官套莫娜buff情况 
			ysjt=ysjt+120;
			shjc=shjc+0.6;
		}
};

class genshinshjs:public Buff{
	public:
		double q;
		double w;
		
		void sha(int a){
			if(a==1){
				q=gjl*bl*(1+shjc)*(100+rwdj)/(200+rwdj+gwdj)*(1-gwfyl);//没暴击 
			}
			else{
				q=gjl*bl*(1+bjsh)*(1+shjc)*(100+rwdj)/(200+rwdj+gwdj)*(1-gwfyl);//暴击 
			}
		}
		void shb(int a){
			if(a==1){
				w=1.5*(2.78*ysjt/(ysjt+1400)+1);//火打水，冰打火 
			}
			if(a==2){
				w=2*(2.78*ysjt/(ysjt+1400)+1);//水打火，火打冰 
			}
			if(a==3){
				w=1;
			}
		}
		double zzsh(void){
			return q*w;
		}
}; 
int main(){
	double a,b,c,d,e,f,g,h;
	int i;
	int j;
	double q;
	double w;
	int a1;
	int b1;
	int c1;
	cout<<"请依次输入人物攻击力，技能倍率，暴击伤害，暴击率，伤害加成，人物等级，怪物等级，怪物对应抗性，元素精通"<<endl;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    genshinshjs sh;
asd:sh.getjbxx(a,b,c,d,e,f,g,h,i);
    cout<<"请选择所加buff：1.风套万叶 2.宗室套班尼特 3.教官套莫娜 4.不上buff（可多选）"<<endl;
	cin>>j;
	switch(j){
		case 1:cout<<"请输入万叶精通"<<endl;
		cin>>q;
		sh.getwyBuff(q);
		break;
		
		case 2:cout<<"请输入班尼特基础攻击力"<<endl;
		cin>>w;
		sh.getbntBuff(w);
		break;
		
		case 3:sh.getmnBuff();
		break;
		
		case 12:cout<<"请输入万叶精通"<<endl;
		cin>>q;
		sh.getwyBuff(q);
		cout<<"请输入班尼特基础攻击力"<<endl;
		cin>>w;
		sh.getbntBuff(w);
		break;
		
		case 13:cout<<"请输入万叶精通"<<endl;
		cin>>q;
		sh.getwyBuff(q);
		sh.getmnBuff();
		break;
		
		case 23:cout<<"请输入班尼特基础攻击力"<<endl;
		cin>>w;
		sh.getbntBuff(w);
		sh.getmnBuff();
		break;
		
		case 123:cout<<"请输入万叶精通"<<endl;
		cin>>q;
		sh.getwyBuff(q);
		cout<<"请输入班尼特基础攻击力"<<endl;
		cin>>w;
		sh.getbntBuff(w);
		sh.getmnBuff();
		break;
		case 4:break;
	}
	cout<<"请选择是否暴击：1.不暴击 2.暴击"<<endl;
	cin>>a1;
	sh.sha(a1);
	cout<<"请输入反应类型：1.火打水，冰打火 2.水打火，火打冰 3.无反应"<<endl;
	cin>>b1;
	sh.shb(b1);
	cout<<"最终伤害是："<<sh.zzsh()<<endl;
	cout<<"是否变更情形：1.是 2.退出"<<endl;
	cin>>c1;
	if(c1==1){
		goto asd;
	}
	else if(c1==2){
		exit(0);
    }
	return 0;
} 
