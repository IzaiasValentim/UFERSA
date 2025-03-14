package POO.UND1.LISTA.Q10;

public class MaiorValorV2 {

	public static int maiorEntreDois(int v1, int v2) {
		return Math.max(v1, v2);
	}

	public static int maiorEntreTres(int v1, int v2, int v3) {
		int res = Math.max(v1, v2);
		res = Math.max(res, v3);
		return res;
	}

	public static int maiorEntreQuatro(int v1, int v2, int v3, int v4) {
		int res = Math.max(v1,v2);
		res = Math.max(res, v3);
		res = Math.max(res, v4);
		return res;
	}

	public static int maiorEntreCinco(int v1, int v2, int v3, int v4, int v5) {
		int res = Math.max(v1, v2);
		res = Math.max(res, v3);
		res = Math.max(res, v4);
		res = Math.max(res, v5);
		return res;
	}

}
