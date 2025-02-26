
public class Q5_Programa {
	public static void main(String[] args) {
		Q5_Conta c1 = new Q5_Conta();
		c1.depositar(1000);
		Q5_Conta c2 = c1;
		c1.sacar(500);
		System.out.println(c1.saldo);

		// Resposta: B - 500.0
	}
}
