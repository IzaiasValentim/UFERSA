package POO.UND1.LISTA.Q9;

public class Main {
	public static void main(String args[]) {
		NumeroComplexo nConstCompleto = new NumeroComplexo(10.0, 3.0);
		NumeroComplexo nConstParcial = new NumeroComplexo(7.0);
		NumeroComplexo nConstVazio = new NumeroComplexo();

		System.out.println("Com construtor completo: "+nConstCompleto);
		System.out.println("Com construtor parcial: "+nConstParcial);
		System.out.println("Com construtor vazio: "+nConstVazio);

		nConstVazio.setParteReal(19.0);
		nConstVazio.setParteImaginaria(1.0);

		System.out.println("Com construtor vazio, utilizando os setters: "+nConstVazio);
	}

}
