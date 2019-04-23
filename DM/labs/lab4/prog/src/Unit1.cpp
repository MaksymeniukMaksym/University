




//---------------------------------------------------------------------------
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vcl.h>

#pragma hdrstop

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class minterm {
public:
	int a[4];
	int size;
	minterm(){
		size=0;
	}
	minterm(int A,int B,int C,int D){
		size=4;
		a[0]=A;
		a[1]=B;
		a[2]=C;
		a[3]=D;
	}
	void fill(int A,int B,int C,int D){
		a[0]=A;
		a[1]=B;
		a[2]=C;
		a[3]=D;
	}

	bool operator == (const minterm &m){
		for(int i=0;i<size;i++){
			if(a[i]!=m.a[i]) return 0;
		}
		return 1;
	}
	bool operator != (const minterm &m){
		for(int i=0;i<size;i++){
			if(a[i]!=m.a[i]) return 1;
		}
		return 0;
	}
	bool not_void(){
		for(int i=0;i<size;i++){
			if(a[i]!=-1) return 1;
		}
		return 0;
	}
	bool include(const minterm &m)
	{
		for(int k=0;k<4;k++)
		{
			if(m.a[k]!=-1 && a[k]!=m.a[k])
				return 0;
		}
		return 1;
	}
	int count_1()
	{
		int c=0;
		for(int i=0;i<4;i++)
			if(a[i]==1)
				c++;
		return c;
	}
	bool positions_coincide(const minterm &m)
	{
		for(int i=0;i<4;i++)
			if(a[i]==-1 && a[i]!=m.a[i])
				return 0;
		return 1;
	}
	bool can_be_united(const minterm &m)
	{
		for(int k=0;k<4;k++)
		{
			if(a[k]!=m.a[k])
			{
				for(int i=k+1;i<4 && k<3;i++)
					if(a[i]!=m.a[i]) return false;
				return true;
			}
		}
		return true;
    }
	void glue(const minterm &m)
	{
		for(int k=0;k<4;k++)
		{
			if(a[k]!=m.a[k])
			{
				for(int i=k+1;i<4 && k<3;i++)
					if(a[i]!=m.a[i]) return;
				a[k]=-1;
				return;
			}
		}
    }
	AnsiString print(){
	AnsiString s;
		if(!(a[0]==-1 && a[1]==-1 && a[2]==-1 && a[3]==-1)){
				if(a[0]==1)
				s=s+"A";
				if(a[0]==0)
				s=s+"!A";
				if(a[1]==1)
				s=s+"B";
				if(a[1]==0)
				s=s+"!B";
				if(a[2]==1)
				s=s+"C";
				if(a[2]==0)
				s=s+"!C";
				if(a[3]==1)
				s=s+"D";
				if(a[3]==0)
				s=s+"!D";

		}
		return s;
	}

};
//---------------------------------------------------------------------------
class fal{
public:
	minterm *mdnf;
	int size,param;
	class Table;
	fal(){
		size=0;
		mdnf=0;
		param=0;
	}
	fal(const AnsiString s,int param_){
		minterm table[16]={
		minterm(0,0,0,0),minterm(0,0,0,1),minterm(0,0,1,0),minterm(0,0,1,1),
		minterm(0,1,0,0),minterm(0,1,0,1),minterm(0,1,1,0),minterm(0,1,1,1),
		minterm(1,0,0,0),minterm(1,0,0,1),minterm(1,0,1,0),minterm(1,0,1,1),
		minterm(1,1,0,0),minterm(1,1,0,1),minterm(1,1,1,0),minterm(1,1,1,1)};
		int lenght=s.Length();
		param=param_;
		char* f= s.c_str();
		for(int i=0;i<lenght;i++){
			f[i]=f[i]-48;
		}
		size=0;
		for(int i=0;i<lenght;i++){
			if(f[i]==1){
				++size;
			}
		}

		mdnf=new minterm[size];
		int j=0,koef=1;
		if(param==3) koef=2;
		if(param==2) koef=4;
		for(int i=0;i<lenght;i++){
			if(f[i]==1){
				mdnf[j]=table[koef*i];
				for(int k=param;k<4;++k)
					mdnf[j].a[k]=-1;
				j++;
			}
		}
	}
	fal(const Table &t,int param_)
	{
		mdnf=new minterm[t.size];
		size=t.size;
		param=param_;
		for (int i = 0; i < size; i++) {
			mdnf[i]=t.row[i]->m;
		}
	}
	~fal(){
		delete[] mdnf;
	}
	AnsiString print(){
		int i;
		AnsiString s;
		for(i=0;!mdnf[i].not_void() && i<size;i++);
			s=s+mdnf[i].print();
		for(i=i+1;i<size;i++)
			if(mdnf[i].not_void()){
				s=s+" v ";
				s=s+mdnf[i].print();
			}
		s=s+"\n";
		return s;
	}
	int count(){
	int n=0;
	for(int i=0;i<size;i++)
		if(mdnf[i].not_void()) n++;
	return n;
	}
//---------------------------------------------------------------------------
	class Row
	{
	public:
		int index;
		int index_arr[8];
		minterm m;
		int n;
		bool united;
		Row()
		{
		index=n=0;
		}
		Row(int index_,minterm m_)
		{
			m=m_;
			united=0;
			index=index_+1;
			for(int i=1;i<8;i++)
			   index_arr[i]=0;
			index_arr[0]=index;
			n=m.count_1();
		}
		Row(const Row &r)
		{
			m=r.m;
			united=r.united;
			index=r.index;
			for(int i=0;i<8;i++)
			   index_arr[i]=r.index_arr[i];
			n=r.n;
		}


		Row *Unite(Row &r)
		{
			Row *new_row=new Row(r);
			united=r.united=true;
			new_row->united=0;
			new_row->m.glue(m);
			for(int i=0;i<8;i++)
				if(new_row->index_arr[i]==0)
				{
					for(int j=0;j<8 && index_arr[j]!=0;j++)
						new_row->index_arr[i++]=index_arr[j];
					break;
				}
			new_row->n=new_row->m.count_1();
			return new_row;
		}
		void print()
		{
			Form1->Label10->Caption=Form1->Label10->Caption+"| "+index+" | "
			+index_arr[0]+' '+index_arr[1]+' '+
			index_arr[2]+' '+index_arr[3]+' '+index_arr[4]+' '+index_arr[5]+' '+
			index_arr[6]+' '+index_arr[7]+' '+" | "+m.print()+" | "+n+" | "
			+(int)united+" | \n";
		}
		bool find_in_index_arr(int n)
		{
			 for(int i=0;i<8;i++)
				if(index_arr[i]==n)
					return 1;
			 return 0;
		}

	};
	//---------------------------------------------------------------------------
	class Table
	{

	public:
		Row **row;
		int size,real_size;
		Table(int size)
		{
		   this->size=size;
		   real_size=size;
		   row=new Row*[size];
		}
		Table(const fal &sdnf)
		{
			size=sdnf.size;
			real_size=size;
			row=new Row*[size];
			for(int i=0;i<size;i++)
				row[i]=new Row(i,sdnf.mdnf[i]);

		}
		~Table()
		{
			delete[] row;
		}
		void print()
		{
			Form1->Label10->Caption=Form1->Label10->Caption+"size="+size+
			" rs="+real_size+"\n";
		   for(int i=0;i<size;i++)
			   row[i]->print();
		   Form1->Label10->Caption=Form1->Label10->Caption+"\n";
		}
		Table &operator = (const Table &t)
		{

			if(&t==this) return *this;

			Row **n=new Row*[t.real_size];
			for (int i = 0; i < t.real_size; i++) {
				n[i]=t.row[i];
			}
			for(int i=0;i<real_size;i++)
			delete[] row;
			row=n;
			size=t.size;
			real_size=t.real_size;
			return *this;

		}
		bool shorten()
		{
			bool changes=false;
			Table *new_table;
			int new_size=0;
			new_table=new Table(3*size);
			for (int i=0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if((row[i]->index!=row[j]->index && row[i]->n==(row[j]->n+1)
					 && row[i]->m.can_be_united(row[j]->m) &&
						row[i]->m.positions_coincide(row[j]->m)))
						{
							new_table->row[new_size]=row[i]->Unite(*row[j]);
							new_table->row[new_size]->index=new_size;
							new_size=new_size+1;
							changes=true;
						}
				}
			}
			for (int i=0; i < size; i++)
			{
				if(!(row[i]->united))
				{
				   new_table->row[new_size]=row[i];
				   new_table->row[new_size]->index=new_size;
				   ++new_size;
				}
			}
			*this=*new_table;
			size=new_size;
			return changes;
		}
		void remove_eq_rows()
		{

			for (int i=0; i < size; i++)
				for (int j = 0; j < size; j++)
					if(row[i]->index!=row[j]->index &&
					row[i]->m==row[j]->m && !(row[i]->united))
						row[j]->united=1;
			this->shorten();
		}
		bool find(int n, int r)
		{
			for (int i=0; i < size; i++)
				if(r!=i)
				{
					if(row[i]->find_in_index_arr(n))
						return true;
				}
			return false;
		}
		bool find_in_core(int n, int r)
		{
			for (int i=0; i < size; i++)
				if(r!=i && row[i]->united)
				{
					if(row[i]->find_in_index_arr(n))
						return true;
				}
			return false;
		}
		Row *find_and_add_in_core(int n, int r)
		{
			for (int i=0; i < size; i++)
				if(r!=i && !row[i]->united)
				{
					if(row[i]->find_in_index_arr(n))
					{
						row[i]->united=1;
						return new Row(*row[i]);
					}
				}
			return 0;
		}
		void minimize()
		{
			Table *new_table;
			Row *new_row=0;
			int new_size=0;
			new_table=new Table(size);
			for (int i=0; i < size; i++)
				{
					for (int n=0; n < 8; n++)
						if(!this->find(row[i]->index_arr[n],i)){
							row[i]->united=1;
							new_table->row[new_size]=new Row(*row[i]);
							++new_size;
							break;
						}
				}
			 for (int i=0; i < size; i++)
				for (int n=0; n < 8; n++)
					if(row[i]->united!=1 && row[i]->index_arr[n]!=0)
						if(!this->find_in_core(row[i]->index_arr[n],i))
						{
							new_row=
							this->find_and_add_in_core(row[i]->index_arr[n],i);
							if(new_row)
							{
								new_table->row[new_size]=new_row;
								++new_size;
							}
						}
				*this=*new_table;
				size=new_size;

		}



	};
};



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void print_element_not(int x,int y){
	 Form1->Image1->Canvas->MoveTo(x,y);
	 Form1->Image1->Canvas->LineTo(x,y+25);
	 Form1->Image1->Canvas->LineTo(x-50,y+25);
	 Form1->Image1->Canvas->LineTo(x-50,y-25);
	 Form1->Image1->Canvas->LineTo(x,y-25);
	 Form1->Image1->Canvas->LineTo(x,y);
	 Form1->Image1->Canvas->Ellipse(x+5,y-5,x-5,y+5);
}
void print_dot(int x,int y){
	 Form1->Image1->Canvas->Brush->Color=0;
	 Form1->Image1->Canvas->Ellipse(x+3,y-3,x-3,y+3);
	 Form1->Image1->Canvas->FloodFill(x,y,0,fsBorder);
	 Form1->Image1->Canvas->Brush->Color=clBtnFace;
}
void print_element_and(int x,int y,const minterm &m){
	 Form1->Image1->Canvas->MoveTo(x,y);
	 Form1->Image1->Canvas->LineTo(x,y+25);
	 Form1->Image1->Canvas->LineTo(x-50,y+25);
	 Form1->Image1->Canvas->LineTo(x-50,y-25);
	 Form1->Image1->Canvas->LineTo(x,y-25);
	 Form1->Image1->Canvas->LineTo(x,y);
	 Form1->Image1->Canvas->TextOut(x-25,y-10,"&");
	 Form1->Image1->Canvas->MoveTo(x,y);
	 Form1->Image1->Canvas->LineTo(x+20,y);
	 if(m.a[0]==1)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y-15);
		Form1->Image1->Canvas->LineTo(10,y-15);
		print_dot(10,y-15);
	 }
	 if(m.a[0]==0)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y-15);
		Form1->Image1->Canvas->LineTo(160,y-15);
		print_dot(160,y-15);
	 }
	 if(m.a[1]==1)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y-5);
		Form1->Image1->Canvas->LineTo(30,y-5);
		print_dot(30,y-5);
	 }
	 if(m.a[1]==0)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y-5);
		Form1->Image1->Canvas->LineTo(180,y-5);
		print_dot(180,y-5);
	 }
	 if(m.a[2]==1)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y+5);
		Form1->Image1->Canvas->LineTo(50,y+5);
		print_dot(50,y+5);
	 }
	 if(m.a[2]==0)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y+5);
		Form1->Image1->Canvas->LineTo(200,y+5);
		print_dot(200,y+5);
	 }
	 if(m.a[3]==1)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y+15);
		Form1->Image1->Canvas->LineTo(70,y+15);
		print_dot(70,y+15);
	 }
	 if(m.a[3]==0)
	 {
		Form1->Image1->Canvas->MoveTo(x-50,y+15);
		Form1->Image1->Canvas->LineTo(220,y+15);
		print_dot(220,y+15);
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{


		AnsiString s = Edit1->Text;
		int param_=(int)*ComboBox1->Text.c_str()-48;
		if(Edit1->Text=="1111111111111111" ||  Edit1->Text=="11111111" ||
		Edit1->Text=="1111")
		{
		   Label3->Caption=1;
		   Label8->Caption=1;
		   Label1->Caption=1;
		   TRect tRect(0,0,Image1->Width,Image1->Height);
		   Image1->Canvas->FillRect(tRect);
		   return;
		}
		if(Edit1->Text=="0000000000000000" ||  Edit1->Text=="00000000" ||
		Edit1->Text=="0000")
		{
		   Label3->Caption=0;
		   Label8->Caption=0;
		   Label1->Caption=0;
		   TRect tRect(0,0,Image1->Width,Image1->Height);
		   Image1->Canvas->FillRect(tRect);
		   return;
		}
		fal k(s,param_);
		fal::Table t(k);
		while(t.shorten());
		t.remove_eq_rows();
		fal f(t,param_);
		Label3->Caption=f.print();
		//t.print();
		t.minimize();
		//t.print();
		Label1->Caption=k.print();
		fal l(t,param_);
		Label8->Caption=l.print();

		int height=l.count()*70+500;
		Image1->Height=height;
		TRect tRect(0,0,Image1->Width,Image1->Height);
		Image1->Canvas->FillRect(tRect);
		int x=0;
		//ABCD
		Image1->Canvas->MoveTo(x+10,20);
		Image1->Canvas->LineTo(x+10,height);
		Image1->Canvas->TextOut(x+10-2,10,"A");
		Image1->Canvas->MoveTo(x+30,20);
		Image1->Canvas->LineTo(x+30,height);
		Image1->Canvas->TextOut(x+30-2,10,"B");
		Image1->Canvas->MoveTo(x+50,20);
		Image1->Canvas->LineTo(x+50,height);
		Image1->Canvas->TextOut(x+50-2,10,"C");
		Image1->Canvas->MoveTo(x+70,20);
		Image1->Canvas->LineTo(x+70,height);
		Image1->Canvas->TextOut(x+70-2,10,"D");
		//!A!B!C!D
		x+=150;
		Image1->Canvas->MoveTo(x+10,20);
		Image1->Canvas->LineTo(x+10,height);
		Image1->Canvas->TextOut(x+10-4,10,"!A");
		Image1->Canvas->MoveTo(x+30,20);
		Image1->Canvas->LineTo(x+30,height);
		Image1->Canvas->TextOut(x+30-4,10,"!B");
		Image1->Canvas->MoveTo(x+50,20);
		Image1->Canvas->LineTo(x+50,height);
		Image1->Canvas->TextOut(x+50-4,10,"!C");
		Image1->Canvas->MoveTo(x+70,20);
		Image1->Canvas->LineTo(x+70,height);
		Image1->Canvas->TextOut(x+70-4,10,"!D");
		//!A
		Image1->Canvas->MoveTo(x+10,70);
		print_dot(x+10,70);
		Image1->Canvas->LineTo(140,70);
		print_element_not(140,70);
		Image1->Canvas->MoveTo(140-50,70);
		Image1->Canvas->LineTo(10,70);
		print_dot(10,70);
		//!B
		Image1->Canvas->MoveTo(x+30,130);
		print_dot(x+30,130);
		Image1->Canvas->LineTo(140,130);
		print_element_not(140,130);
		Image1->Canvas->MoveTo(140-50,130);
		Image1->Canvas->LineTo(30,130);
		print_dot(30,130);
		//!C
		Image1->Canvas->MoveTo(x+50,190);
		print_dot(x+50,190);
		Image1->Canvas->LineTo(140,190);
		print_element_not(140,190);
		Image1->Canvas->MoveTo(140-50,190);
		Image1->Canvas->LineTo(50,190);
		print_dot(50,190);
		//!D
		Image1->Canvas->MoveTo(x+70,250);
		print_dot(x+70,250);
		Image1->Canvas->LineTo(140,250);
		print_element_not(140,250);
		Image1->Canvas->MoveTo(140-50,250);
		Image1->Canvas->LineTo(70,250);
		print_dot(70,250);
		//& и 1
		int n=0;
		Image1->Canvas->MoveTo(370,300);
		Image1->Canvas->LineTo(320,300);
		for(int i=0;i<l.size;i++)
		{
			if(l.mdnf[i].not_void())
			{

				Image1->Canvas->LineTo(320,300+n*60);
				print_element_and(300,325+n*60,l.mdnf[i]);
				Image1->Canvas->MoveTo(320,300+n*60);

				n++;
			}
		}
		Image1->Canvas->LineTo(320,300-10+n*60);
		Image1->Canvas->LineTo(370,300-10+n*60);
		Image1->Canvas->LineTo(370,300);
		Image1->Canvas->MoveTo(370,(300+300-10+n*60)/2);
		Image1->Canvas->LineTo(450,(300+300-10+n*60)/2);
		Image1->Canvas->TextOut(400,(300+300-10+n*60)/2-12,"Выход");
		Image1->Canvas->TextOut(345,(300+300-10+n*60)/2-12,"1");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	AnsiString s = ComboBox1->Text;
	char* n= s.c_str();
	switch(n[0])
	{
	case '2':
		Edit1->MaxLength=4;
		Edit1->Clear();
		Edit2->Clear();
		ComboBox1->Text=2;
		break;
	case '3':
		Edit1->MaxLength=8;
		Edit1->Clear();
		Edit2->Clear();
		ComboBox1->Text=3;
		break;
	case '4':
		Edit1->MaxLength=16;
		Edit1->Clear();
		Edit2->Clear();
		ComboBox1->Text=4;
		break;
	default: ComboBox1->Text=4; Edit1->MaxLength=16;
	}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit2Change(TObject *Sender)
{

	char n[16];
	if(Edit2->Text.Length()>0){
		Edit1->Clear();
		for (int i = 0; i < Edit1->MaxLength; i++) {
			n[i]='0';

		}

		for (int i = 1; i < Edit2->Text.Length(); i++)
		{
			 switch(Edit2->Text[i])
			 {
			 case '0':
			 case '2':
			 case '3':
			 case '4':
			 case '5':
			 case '6':
			 case '7':
			 case '8':
			 case '9':
				  n[(int)Edit2->Text[i]-48]='1'; break;
			 case '1':
				switch(Edit2->Text[i+1])
				{
				 case '0':
				 case '1':
				 case '2':
				 case '3':
				 case '4':
				 case '5':
					n[10+(int)Edit2->Text[i+1]-48]='1';
					++i;
					break;
				 case ',':
				 case ' ': n[1]='1'; break;
				 default:  n[1]='1'; break;
				}
				break;
			  case ',':
			  case ' ': break;
			  default:  break;
			 }
		}
		for (int i = 0; i < Edit1->MaxLength; i++)
			Edit1->Text=Edit1->Text+n[i];
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	AnsiString s = Edit1->Text;
	char* n= s.c_str();
	Edit2->Clear();
	for (int i = 0; i < Edit1->MaxLength; i++)
	 {
		 if(n[i]=='1'){
			Edit2->Text=Edit2->Text+i+',';

		 }
	 }
}

//---------------------------------------------------------------------------

