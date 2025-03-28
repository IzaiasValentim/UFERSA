package POO.UND3.LISTA.Q41;

import POO.UND3.LISTA.Q40.FiguraGeometrica;

public class Desenho {
	FiguraGeometrica figuraUm;
	FiguraGeometrica figuraDois;

	Desenho(FiguraGeometrica figUm, FiguraGeometrica figDois, int coordUm[], int coordDois[]) {
		figUm.definirCoordenadas(coordUm);
		figDois.definirCoordenadas(coordDois);

		this.figuraUm = figUm;
		this.figuraDois = figDois;
	}

	public void apresenta() {
		System.out.println("Descrição figura 1:");
		figuraUm.descricao();
		System.out.println("Descrição figura 2:");
		figuraDois.descricao();
	}
}
