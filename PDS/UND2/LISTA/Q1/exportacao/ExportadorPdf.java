package Q1.exportacao;

// Classe concreta específica para a exportação de PDF.
// Implementa a interface IExportarDocumentos, que centraliza a assinatura padrão do FM.

public class ExportadorPdf implements IExportarDocumentos {

	@Override
	public String exportar(String valor) {
		return String.format("O documento está sendo exportado para PDF: %s", valor);
	}
	
}
