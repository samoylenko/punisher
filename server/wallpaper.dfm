object frmWallpaper: TfrmWallpaper
  Left = 387
  Top = 320
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Wallpaper'
  ClientHeight = 126
  ClientWidth = 467
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 4
    Top = 1
    Width = 380
    Height = 121
    TabOrder = 0
    object Label1: TLabel
      Left = 48
      Top = 19
      Width = 27
      Height = 13
      Caption = #1055#1091#1090#1100':'
    end
    object Label2: TLabel
      Left = 13
      Top = 48
      Width = 62
      Height = 13
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099':'
    end
    object cbPath: TComboBox
      Left = 80
      Top = 16
      Width = 269
      Height = 21
      ItemHeight = 13
      TabOrder = 0
    end
    object BitBtn3: TBitBtn
      Left = 352
      Top = 16
      Width = 21
      Height = 21
      Action = Browse
      Caption = '...'
      TabOrder = 1
    end
    object rgParams: TRadioGroup
      Left = 80
      Top = 40
      Width = 293
      Height = 73
      ItemIndex = 0
      Items.Strings = (
        'Stretch'
        'Tile'
        'Center')
      TabOrder = 2
    end
  end
  object BitBtn1: TBitBtn
    Left = 388
    Top = 5
    Width = 75
    Height = 22
    Action = Ok
    Caption = 'OK'
    Default = True
    TabOrder = 1
    Glyph.Data = {
      42020000424D4202000000000000420000002800000010000000100000000100
      1000030000000002000000000000000000000000000000000000007C0000E003
      00001F0000001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C1F7CD042A105C209C30DC30DE30DE209E209E105E105E001E001
      C001CF3E1F7C1F7C020A230E451645164516451665166412830E820A81066002
      4002A0011F7C1F7C230E4516661A671E671E871E54531F7CA412C30EC20AA106
      6002E0011F7C1F7C4412671E88228926882288221F7C1F7C1F7CC412C30EC106
      8106E0011F7C1F7C451688228926892689268822A8221F7C1F7C1F7CC30EA20A
      810601061F7C1F7C661A8926AA2AAA2AA9268926A822A71E1F7C1F7C1F7CA30E
      830E020A1F7C1F7C671EAA2A1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      630E030E1F7C1F7C8822AB2E1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      6412E30D1F7C1F7C8926CC32AC32AB2E8A2A8926671E661A1F7C1F7C1F7C6412
      4516E4111F7C1F7CAA2ACD36CD36AB2EAA2A892668221F7C1F7C1F7C45166516
      4516E4111F7C1F7CAB2EEF3EEE3ACC32AB2E8A2A1F7C1F7C1F7C661A661A661A
      4516E4111F7C1F7CCD3611471043CD36CC32AC32765B1F7C892689268822671E
      461AE30D1F7C1F7CEE3A334F1147EF3EEE3ACD36CC32CC32AB2EAA2A89268822
      4516C30D1F7C1F7C765BEE3ACC32AB2EAA2A8926892689268822871E671E661A
      2412F1461F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C}
    Margin = 5
  end
  object BitBtn2: TBitBtn
    Left = 388
    Top = 29
    Width = 75
    Height = 22
    Action = Cancel
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    Glyph.Data = {
      42020000424D4202000000000000420000002800000010000000100000000100
      1000030000000002000000000000000000000000000000000000007C0000E003
      00001F0000001F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C9C73DE7B1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      DE7B1F7C1F7C1F7C1F7C266C056CCE391F7C1F7C1F7C1F7C1F7C1F7C1F7CB65E
      465C9C731F7C1F7C1F7CAA70056CA73C5A6B1F7C1F7C1F7C1F7C1F7C2B5D056C
      B66E1F7C1F7C1F7C1F7C1F7C266C056C4A29BD771F7C1F7C1F7C6764056CBD77
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C056C056C8C31DE7B1F7C6764056CBD771F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C056C0568AD354764056CBD771F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C266C056C056C7B6F1F7C1F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C256C056C056C6B2D9C731F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C6764056C9C738F75056C292D39671F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C6764056C5A6B1F7C1F7C3A7F056CE83C734E
      1F7C1F7C1F7C1F7C1F7CDE7B4664056CD6621F7C1F7C1F7C1F7C1F7C056C6760
      39671F7C1F7C1F7C1F7C256C056C8D591F7C1F7C1F7C1F7C1F7C1F7C1F7C757A
      1F7C1F7C1F7C1F7C1F7C056C67601F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C1F7C
      1F7C1F7C1F7C}
    Margin = 5
  end
  object ActionList1: TActionList
    Images = frmMain.ImageListBtns
    Left = 208
    Top = 8
    object Ok: TAction
      Caption = 'OK'
      ImageIndex = 5
      OnExecute = OkExecute
    end
    object Cancel: TAction
      Caption = #1054#1090#1084#1077#1085#1072
      ImageIndex = 0
      OnExecute = CancelExecute
    end
    object Browse: TAction
      Caption = '...'
      OnExecute = BrowseExecute
    end
  end
end
