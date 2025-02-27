package POO.UND1.LISTA.Q8;

public class Main {
	public static void main(String args[]) {
		Lampada lampada = new Lampada();

		lampada.acende();
		lampada.acende();
		System.out.println(lampada.estahLigada());
		lampada.vezesLigada(); // 2

		lampada.apaga();
		System.out.println(lampada.estahLigada());

		lampada.acende();
		lampada.vezesLigada(); // 3
	}
}
