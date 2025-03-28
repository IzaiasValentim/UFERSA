package POO.UND3.LISTA.Q41;

import POO.UND3.LISTA.Q40.Circulo;
import POO.UND3.LISTA.Q40.Quadrado;
import POO.UND3.LISTA.Q40.Triangulo;

public class Main {
	public static void main(String[] Args) {
		// Criação do circulo e suas coordenadas do centro xy e raio
		Circulo circuloUm = new Circulo();
		int cordCUm[] = { 0, 0, 4 };

		// Criação do quadrado e suas coordendas x y
		Quadrado quadradoUm = new Quadrado();
		int cordQUm[] = { 0, 0, 0, 1, 1, 0, 1, 1 };

		// Criação do primeiro desenho passando as figuras e respectivas coordenadas.
		Desenho desenhoUm = new Desenho(circuloUm, quadradoUm, cordCUm, cordQUm);
		System.out.println("Desenho um:\n");
		desenhoUm.apresenta();

		Quadrado quadradoDois = new Quadrado();
		int coordQDois[] = { 0, 0, 0, 1, 1, 0, 1, 1 };

		Triangulo triangulo = new Triangulo();
		int coordT[] = { 0, 0, 0, 1, 1, 1 };

		// Criação do segundo desenho passando as figuras e respectivas coordenadas.
		Desenho desenhoDois = new Desenho(quadradoDois, triangulo, coordQDois, coordT);
		System.out.println("\nDesenho dois:\n");
		desenhoDois.apresenta();
	}
}
