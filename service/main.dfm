object PunisherService: TPunisherService
  OldCreateOrder = False
  DisplayName = 'OITZI Remote Computer Control  Service'
  ErrorSeverity = esSevere
  Interactive = True
  OnStart = ServiceStart
  Left = 256
  Top = 155
  Height = 150
  Width = 215
  object xmlIn: TXMLDocument
    Active = True
    XML.Strings = (
      '<request>'
      '  <node1>Hello!</node1>'
      '</request>')
    Left = 72
    Top = 56
    DOMVendorDesc = 'MSXML'
  end
  object strmP: TNMStrm
    Host = '10.0.17.1'
    Port = 6711
    ReportLevel = 0
    FromName = 'PunisherService'
    Left = 24
    Top = 8
  end
  object ssP: TNMStrmServ
    Port = 6712
    ReportLevel = 0
    OnMSG = ssPMSG
    Left = 72
    Top = 8
  end
  object xmlOut: TXMLDocument
    Left = 24
    Top = 56
    DOMVendorDesc = 'MSXML'
  end
end
