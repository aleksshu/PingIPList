object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Ping IP List'
  ClientHeight = 571
  ClientWidth = 525
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  ShowHint = True
  OnCreate = FormCreate
  DesignSize = (
    525
    571)
  PixelsPerInch = 96
  TextHeight = 13
  object TimeOut: TLabel
    Left = 445
    Top = 187
    Width = 60
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'TimeOut, ms'
    ExplicitLeft = 442
  end
  object StringGrid1: TStringGrid
    Left = 3
    Top = 3
    Width = 436
    Height = 547
    Anchors = [akLeft, akTop, akRight, akBottom]
    ColCount = 2
    FixedCols = 0
    RowCount = 5555
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    TabOrder = 0
    ExplicitWidth = 433
    ExplicitHeight = 300
  end
  object PingStartBtn: TButton
    Left = 445
    Top = 91
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Start ping'
    TabOrder = 1
    OnClick = PingStartBtnClick
    ExplicitLeft = 442
  end
  object LoadBtn: TButton
    Left = 445
    Top = 20
    Width = 75
    Height = 25
    Hint = 
      'Load file with IP addresses if "IP.txt" not exist in working dir' +
      'ectory'
    Anchors = [akTop, akRight]
    Caption = 'Load'
    TabOrder = 2
    OnClick = LoadBtnClick
    ExplicitLeft = 442
  end
  object SaveBtn: TButton
    Left = 445
    Top = 56
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Save'
    TabOrder = 3
    OnClick = SaveBtnClick
    ExplicitLeft = 442
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 552
    Width = 525
    Height = 19
    Panels = <
      item
        Width = 500
      end>
    ExplicitTop = 305
    ExplicitWidth = 522
  end
  object TimeOutEdt: TEdit
    Left = 445
    Top = 203
    Width = 75
    Height = 21
    Anchors = [akTop, akRight]
    TabOrder = 5
    Text = '3000'
    ExplicitLeft = 442
  end
  object StopPingBtn: TButton
    Left = 445
    Top = 125
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Stop'
    Enabled = False
    TabOrder = 6
    OnClick = StopPingBtnClick
    ExplicitLeft = 442
  end
  object ScrolChkBx: TCheckBox
    Left = 446
    Top = 239
    Width = 71
    Height = 17
    Caption = 'AutoScroll'
    TabOrder = 7
  end
  object OpenDialog1: TOpenDialog
    Left = 459
    Top = 143
  end
  object SaveDialog1: TSaveDialog
    Left = 451
    Top = 335
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 150
    OnTimer = Timer1Timer
    Left = 476
    Top = 370
  end
end
