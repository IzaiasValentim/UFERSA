package POO.UND1.LISTA.Q10;

public class MaiorValor {

	public static double maiorEntreDois(double v1, double v2) {
		if (v1 >= v2) {
			return v1;
		} else {
			return v2;
		}
	}

	public static double maiorEntreTres(double v1, double v2, double v3) {
		if (v1 >= v2 && v1 >= v3) {
			return v1;
		} else if (v2 >= v1 && v2 >= v3) {
			return v2;
		} else {
			return v3;
		}
	}

	public static double maiorEntreQuatro(double v1, double v2, double v3, double v4) {
		if (v1 >= v2 && v1 >= v3 && v1 >= v4) {
			return v1;
		} else if (v2 >= v1 && v2 >= v3 && v2 >= v4) {
			return v2;
		} else if (v3 >= v1 && v3 >= v2 && v3 >= v4) {
			return v3;
		} else {
			return v4;
		}
	}

	public static double maiorEntreCinco(double v1, double v2, double v3, double v4, double v5) {
		if (v1 >= v2 && v1 >= v3 && v1 >= v4 && v1 >= v5) {
			return v1;
		} else if (v2 >= v1 && v2 >= v3 && v2 >= v4 && v2 >= v5) {
			return v2;
		} else if (v3 >= v1 && v3 >= v2 && v3 >= v4 && v3 >= v5) {
			return v3;
		} else if (v4 >= v1 && v4 >= v2 && v4 >= v3 && v4 >= v5) {
			return v4;
		} else {
			return v5;
		}
	}

}
