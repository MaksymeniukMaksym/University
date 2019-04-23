//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *Button1;
	TLabel *Label3;
	TLabel *Label2;
	TEdit *Edit1;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TImage *Image1;
	TLabel *Label7;
	TLabel *Label8;
	TComboBox *ComboBox1;
	TLabel *Label9;
	TLabel *Label11;
	TEdit *Edit2;
	TLabel *Label10;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Edit1Exit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
