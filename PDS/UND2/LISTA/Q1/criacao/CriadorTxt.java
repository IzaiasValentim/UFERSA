package Q1.criacao;

import Q1.exportacao.ExportadorTxt;
import Q1.exportacao.IExportarDocumentos;

public class CriadorTxt extends CriarDocumentos{

	@Override
	protected IExportarDocumentos exportarDocumento() {
		return new ExportadorTxt();
	}
	
}
