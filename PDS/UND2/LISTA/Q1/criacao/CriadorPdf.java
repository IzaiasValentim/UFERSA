package Q1.criacao;

import Q1.exportacao.ExportadorPdf;
import Q1.exportacao.IExportarDocumentos;

// Classe concreta que implementa o Factory Method.
// Cada classe concreta irá implementar o método 'fábrica' de sua maneira, seguindo a assinatua do método.

public class CriadorPdf extends CriarDocumentos{

	@Override
	protected IExportarDocumentos exportarDocumento() {
		return new ExportadorPdf();
	}
	

}
