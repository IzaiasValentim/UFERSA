package POO.UND3.LISTA.Q40;

public abstract class Coordenadas2D {
	int coordenadas[];

	public final void definirCoordenadas(int... coordenadas) {
		this.coordenadas = coordenadas;
	}

	public final void mostrarCoordenadas() {
		if (coordenadas == null) {
			System.out.print(" Ainda não definidas");
			return;
		}

		System.out.print("[");
		for (int c : coordenadas) {
			System.out.print(c + " ");
		}
		System.out.print("]\n");
	}
}
