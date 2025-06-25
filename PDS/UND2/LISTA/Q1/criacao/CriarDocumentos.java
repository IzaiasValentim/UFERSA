package Q1.criacao;
import Q1.exportacao.IExportarDocumentos;

public abstract class CriarDocumentos {
	// Factory Method
	protected abstract IExportarDocumentos exportarDocumento();

	public String emitirDocumento(String valor) {
		IExportarDocumentos exportar = exportarDocumento();
		return exportar.exportar(valor);
	}

}