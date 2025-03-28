package POO.UND3.LISTA.Q40;

public class Circulo extends FiguraGeometrica {

	@Override
	public void descricao() {
		System.out.println("Sou um circulo! E meu centro x y e raio é: ");
		this.mostrarCoordenadas();
	}
}
