package POO.UND3.LISTA.Q42;

public class DemoLivroDeBiblioteca {
	public static void main(String[] Args) {
		LivroDeBiblioteca poo = new LivroDeBiblioteca("POO", "Dr ....", 415, 2021, "BCZM");

		System.out.println("Criação:");
		System.out.println(poo.descricao()+"\n");

		System.out.println("Emprestou:");
		poo.empresta();
		System.out.println(poo.descricao()+"\n");

		System.out.println("Devolveu:");
		poo.devolve();
		System.out.println("Está disponível: "+poo.estaEmprestado());
	}
}
