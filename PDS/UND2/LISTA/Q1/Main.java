package Q1;

import Q1.criacao.CriadorPdf;
import Q1.criacao.CriadorTxt;
import Q1.criacao.CriarDocumentos;

public class Main {
	public static void main(String[] args) {
		CriarDocumentos novoPdf = new CriadorPdf();
		CriarDocumentos novoTxt = new CriadorTxt();

		System.out.println(novoPdf.emitirDocumento("Este documento deve ser um pdf."));
		System.out.println(novoTxt.emitirDocumento("Este documento deve ser um Txt."));
	}
}
