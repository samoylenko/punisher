object frmTaskMgr: TfrmTaskMgr
  Left = 196
  Top = 186
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Task Manager'
  ClientHeight = 339
  ClientWidth = 497
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
    Left = 8
    Top = 8
    Width = 369
    Height = 321
    Caption = #1042#1099#1087#1086#1083#1085#1103#1077#1084#1099#1077' '#1079#1072#1076#1072#1095#1080
    TabOrder = 0
    object sgT: TStringGrid
      Left = 8
      Top = 16
      Width = 353
      Height = 297
      ColCount = 4
      DefaultColWidth = 100
      DefaultRowHeight = 16
      FixedCols = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect, goThumbTracking]
      PopupMenu = PopupMenu2
      TabOrder = 0
      OnMouseDown = sgTMouseDown
      ColWidths = (
        26
        64
        73
        407)
    end
  end
  object BitBtn2: TBitBtn
    Left = 384
    Top = 80
    Width = 105
    Height = 25
    Action = ToMainWnd
    Cancel = True
    Caption = #1054#1073#1088#1072#1090#1085#1086
    Default = True
    TabOrder = 1
    Glyph.Data = {
      36040000424D3604000000000000360000002800000010000000100000000100
      2000000000000004000000000000000000000000000000000000FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00F6F6F600C2C2C200C9C9
      C900F2F2F200FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0098BE98008B9E8B007474
      7400ADADAD00EDEDED00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FCFCFC00FF00FF00FF00FF00FF00FF0083B986003FB95900355B
      35005E5E5E00ABABAB00F0F0F000FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FCFCFC00DBDBDB00F3F3F300FF00FF00FF00FF00CEE1CE0044CD670053E2
      7C002E58320061616100BDBDBD00F9F9F900FF00FF00FF00FF00FF00FF00FF00
      FF00CAD6CA007C7C7C00ABABAB00E9E9E900FF00FF00E6ECE60034B7510062FB
      950046CF6900344D340082828200EDEDED00FF00FF00FF00FF00FF00FF00FF00
      FF00118721003A633E00595959009A9A9A00E1E1E10082A8820047D670005CF5
      8F0062FB950023782C005E5E5E00E7E7E700FF00FF00FF00FF00FF00FF00FF00
      FF001A9933002BBA54001F5C230053535300787E78002B963D0052EB850057F0
      8A005CF58F0030B04A0059595900E7E7E700FF00FF00FF00FF00FF00FF00FF00
      FF0017972E0033CC65002BBA54001B5E1F001A76230042D872004CE57F0051EA
      840057F08A002DAC460067676700E9E9E900FF00FF00FF00FF00FF00FF00FF00
      FF00159429002DC65A0033CC65002BBA540033C6600041DA740046DF79004CE5
      7F0051EA84002AA0400094949400F0F0F000FF00FF00FF00FF00FF00FF00FF00
      FF001291240027C04E002DC65A0033CC650035CE68003AD36D0041DA740046DF
      790047DD77002F713200D4D4D400FEFEFE00FF00FF00FF00FF00FF00FF00FF00
      FF000F8E1D0021BA430027C04E002DC65A0033CC650035CE68003AD36D0040D9
      730023993900A5ABA500F9F9F900FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF000B8B17001BB4370021BA420027C04D002CC5580032CB630035CE680028B1
      4B003B4E3B008F8F8F00E1E1E100FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF0008870F0015AE29001AB3350020B9400026BF4C002CC5570032CB630031C7
      6100226B2B005252520094949400E1E1E100FF00FF00FF00FF00FF00FF00FF00
      FF0005850A000FA81D0015AE29001AB3350020B9400026BF4C002CC5570032CB
      630031C66000277030005E5E5E00A0A0A000F0F0F000FF00FF00FF00FF00FF00
      FF000282050009A212000FA81D0015AE29001AB3350020B9400026BF4C002CC5
      570032CB630031C66000468F4F00B4B4B400F3F3F300FF00FF00FF00FF00FF00
      FF008FBB8F007AAD7A0079AC790079AC790079AC790079AC790079AC790079AC
      790079AC790079AC790079AC7900F3F3F300FF00FF00FF00FF00}
    Margin = 5
  end
  object BitBtn1: TBitBtn
    Left = 384
    Top = 16
    Width = 105
    Height = 25
    Action = FullPath
    Caption = #1055#1086#1083#1085#1099#1081' '#1087#1091#1090#1100
    TabOrder = 2
    Glyph.Data = {
      36040000424D3604000000000000360000002800000010000000100000000100
      2000000000000004000000000000000000000000000000000000FF00FF00FF00
      FF00EEEEEE00D0D0D000D0D0D000D0D0D000D0D0D000D0D0D000D0D0D000D0D0
      D000D0D0D000D0D0D000D0D0D000D0D0D000F4F4F400FF00FF00FAFAFA00C3C3
      C300C7947E00C4917B00BF8C7900BB887700B7847500B3807300AF7C7100AB78
      6F00A8756D00A4716B009F6C6A009C696700D0D0D000FF00FF00B7B7B7007171
      8E00C5968A00FFEAD400FFE7CF00FFE4C900FFE1C400FFDFBF00FFDCB900FFD9
      B400FFD6AD00FFD3A800FFD0A2009C696700D0D0D000FF00FF00ABD7F2003B8E
      EA00817BA500F3DCCD00FFEAD400FFE7CF00FFE4C900FFE1C400FFDFBF00FFDC
      B900FFD9B300FFD6AD00FFD3A8009C696700D0D0D000FF00FF00FF00FF007ED1
      FD003C8BE600817BA500F3DCCD00FFEAD400FFE7CF00FFE4C900FFE1C400FFDF
      BF00FFDCB900FFD9B300FFD6AD009C696700D0D0D000FF00FF00FF00FF00FF00
      FF0079C2E8003C85DF007D79A500FFECD900F3DAC700F1D2C000FBDFC500FFE1
      C400FFDFBF00FFDBB800FFD9B3009F6C6800D0D0D000FF00FF00FF00FF00FF00
      FF00DBA887007DCEFB009B9B9B00D1A28F00FFF0C200FFFFD900FFFFDB00C299
      9000FFE1C400FFDEBE00FFDBB800A4716B00D0D0D000FF00FF00FF00FF00FF00
      FF00DEAB8900FFF7EF00D1A29800FFFBCA00FFFFCC00FFFFE400FFFFF900FFFF
      FF00CAA19500FFE1C400FFDEBE00AA766E00D0D0D000FF00FF00FF00FF00FF00
      FF00E2AF8A00FFFAF500FBE3B800FFDBA800FFFFCC00FFFFE400FFFFF400FFFF
      E400CCB39900FFE4C900FFE1C300AF7C7000D0D0D000FF00FF00FF00FF00FF00
      FF00E5B38C00FFFDFB00FFF0BD00FFD9A800FFF2C000FFFFD300FFFFDC00FFFF
      D300D2B29600FFE7CF00FFE3C800B5827300D0D0D000FF00FF00FF00FF00FF00
      FF00E9B68E00FFFFFF00E1C1A700FFFAEC00FFDCB100FFE8B500FFECB900FFF6
      C300B6898000FFEAD400FFE7CE00BA877600D0D0D000FF00FF00FF00FF00FF00
      FF00EEBB9000FFFFFF00F4EAEA00FBF6EE00FFFCE600FFECB900FFFBCA00E0AD
      8D00FFEFDF00FFEAD500FFE8D000C08D7900D0D0D000FF00FF00FF00FF00FF00
      FF00F1BE9200FFFFFF00FFFFFF00FAF7F700BF9A9700D4AB9E00D8B5B200FFF4
      EA00FFF3E600FFE4D500FFD1C500C4917B00D0D0D000FF00FF00FF00FF00FF00
      FF00F6C39400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFCFA00FFFAF400FFF7
      EF00FFF5EC009B6A69009B6A69009B6A6900E5E5E500FF00FF00FF00FF00FF00
      FF00F9C69600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFCFA00FFFA
      F400FFF8F100FDE6B000D19E8200D6D6D600FF00FF00FF00FF00FF00FF00FF00
      FF00FECB9800FFFFFF00FEFEFE00FCFCFC00FBFBFB00FAFAFA00F9F7F700F7F4
      F100F7F3EF00DAA78600D6D6D600FF00FF00FF00FF00FF00FF00}
    Margin = 5
  end
  object BitBtn3: TBitBtn
    Left = 384
    Top = 48
    Width = 105
    Height = 25
    Action = Kill
    Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
    TabOrder = 3
    Glyph.Data = {
      36040000424D3604000000000000360000002800000010000000100000000100
      2000000000000004000000000000000000000000000000000000FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00E7E7E700F3F3F300FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00F3F3F300FF00FF00FF00FF00FF00FF00FF00
      FF00340EDE002900DF0070707000FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00B0AEBB003315BC00E7E7E700FF00FF00FF00FF00FF00
      FF00502FE4002900DF0038297C00D1D1D100FF00FF00FF00FF00FF00FF00FF00
      FF00FEFEFE005E4AB9002900DF00B6AFD900FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00350FDF002900DF0050505000E9E9E900FF00FF00FF00FF00FCFC
      FC003918CD002900DF00EAEAEA00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF002900DF002900DF0061616100F5F5F500FCFCFC003918
      CD002900DF00EDEDED00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF002900DF002C06D6006B6B6B003817CC002900
      DF00EDEDED00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00350FDF002900DF002900DF00DBDB
      DB00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FCFCFC002E08D9002900DF002900DF005959
      5900E3E3E300FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FCFCFC003918CD002900DF00E1E1E1007960EB002900
      DF004C4A5800C9C9C900FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FCFCFC003918CD002900DF00D4D4D400FF00FF00FF00FF00D6CF
      F8002900DF0045387E009A9A9A00FEFEFE00FF00FF00FF00FF00FF00FF00FF00
      FF00F5F5F5003616CB002900DF00B6B4C100FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF002900DF00391BC200CECECE00FF00FF00FF00FF00FF00FF00FF00
      FF002E08D9002900DF006F60B400FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00AD9EF100FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF002900DF003D1FC500FEFEFE00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
      FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    Margin = 5
  end
  object ActionList1: TActionList
    Images = frmMain.ImageListBtns
    Left = 328
    Top = 264
    object ToMainWnd: TAction
      Caption = #1054#1073#1088#1072#1090#1085#1086
      ImageIndex = 1
      OnExecute = ToMainWndExecute
    end
    object FullPath: TAction
      Caption = #1055#1086#1083#1085#1099#1081' '#1087#1091#1090#1100
      ImageIndex = 3
      OnExecute = FullPathExecute
    end
    object Kill: TAction
      Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100
      ImageIndex = 0
      OnExecute = KillExecute
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 296
    Top = 264
    object N1: TMenuItem
      Action = FullPath
    end
    object N2: TMenuItem
      Action = Kill
    end
  end
end