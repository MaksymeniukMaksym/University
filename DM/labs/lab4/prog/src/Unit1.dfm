object Form1: TForm1
  Left = 0
  Top = 0
  Width = 913
  Height = 462
  AutoScroll = True
  Caption = #1052#1080#1085#1080#1084#1080#1079#1072#1094#1080#1103' '#1092#1091#1085#1082#1094#1080#1081' '#1072#1083#1075#1077#1073#1088#1099' '#1083#1086#1075#1080#1082#1080
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 60
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 108
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 41
    Width = 40
    Height = 16
    Caption = #1057#1044#1053#1060':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 89
    Width = 129
    Height = 16
    Caption = #1057#1086#1082#1088#1072#1097#1077#1085#1085#1072#1103' '#1092#1086#1088#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 0
    Width = 15
    Height = 25
    Caption = 'f('
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 132
    Top = 0
    Width = 55
    Height = 25
    Caption = ') = v('
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Image1: TImage
    Left = 7
    Top = 192
    Width = 433
    Height = 100
    Transparent = True
  end
  object Label7: TLabel
    Left = 8
    Top = 127
    Width = 122
    Height = 16
    Caption = #1052#1080#1085#1080#1084#1072#1083#1100#1085#1072' '#1092#1086#1088#1084#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 8
    Top = 146
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 437
    Top = 8
    Width = 129
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1077#1088#1077#1084#1077#1085#1085#1099#1093':'
  end
  object Label11: TLabel
    Left = 295
    Top = 0
    Width = 8
    Height = 25
    Caption = ')'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 576
    Top = 41
    Width = 3
    Height = 13
  end
  object Button1: TButton
    Left = 319
    Top = 2
    Width = 97
    Height = 25
    Caption = #1052#1080#1085#1080#1084#1080#1079#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 24
    Top = 4
    Width = 107
    Height = 21
    MaxLength = 16
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    TextHint = ' '#1042#1074#1077#1076#1080#1090#1077' '#1092#1091#1085#1082#1094#1080#1102
    OnExit = Edit1Exit
  end
  object ComboBox1: TComboBox
    Left = 572
    Top = 4
    Width = 41
    Height = 21
    TabOrder = 2
    Text = '4'
    OnChange = ComboBox1Change
    Items.Strings = (
      '2'
      '3'
      '4')
  end
  object Edit2: TEdit
    Left = 188
    Top = 4
    Width = 107
    Height = 21
    MaxLength = 45
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    TextHint = ' '#1042#1074#1077#1076#1080#1090#1077' '#1074#1077#1082#1090#1086#1088
    OnChange = Edit2Change
  end
end
