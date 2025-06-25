package Q1.exportacao;

// Classe concreta específica para a exportação de txt
// Implementa a interface IExportarDocumentos, que centraliza a assinatura padrão do FM.

public class ExportadorTxt implements IExportarDocumentos{

	@Override
	public String exportar(String valor) {
		
		return String.format("O documento está sendo exportado para TXT: %s", valor);
	}
	
}
