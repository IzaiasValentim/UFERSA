package POO.UND1.LISTA.Q8;

import POO.UND1.LISTA.Q7.Contador;

public class Lampada {
	private boolean estadoDaLampada;// True acesa e False apagada.
	private Contador contador;

	public Lampada() {
		estadoDaLampada = false;
		contador = new Contador();
	}

	public void acende() {
		estadoDaLampada = true;
		contador.incrementaUm();
	}

	public void apaga() {
		estadoDaLampada = false;
	}

	public boolean estahLigada() {
		return estadoDaLampada;
	}

	public void vezesLigada() {
		System.out.println("A lâmpada foi ligada " + contador.getValor() + " vezes.");
	}
}
