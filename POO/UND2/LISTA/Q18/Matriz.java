package POO.UND2.LISTA.Q18;

public class Matriz {
	public static final int L = 2;
	public static final int C = 2;

	private float matriz[][];

	public Matriz(float m[][]) {
		matriz = m;
	}

	public float calcularDeterminante() {
		float dPrincipal = matriz[0][0] * matriz[1][1];
		float dSecundaria = matriz[0][1] * matriz[1][0];

		return dPrincipal - dSecundaria;
	}

	@Override
	public String toString() {
		String formatoMat = "";
		for (int l = 0; l < L; l++) {
			for (int c = 0; c < C; c++) {
				formatoMat += "[" + matriz[l][c] + "]";
			}
			formatoMat += "\n";
		}
		return formatoMat;
	}
}
