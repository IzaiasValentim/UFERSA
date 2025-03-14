package POO.UND2.LISTA.Q32;

public class Main {

	public static void main(String[] args) {
		// Criando um Funcionario base:
		Funcionario base = new Funcionario("Normal", 1455.0);

		// Criando assistente base
		Assistente assistenteBase = new Assistente("Assistente B", 2200.0, "123AB");

		// Criando um assistente técnico com bonus de salário
		Tecnico aTecnico = new Tecnico("Assistente técnico", 3500.0, "123AT", 350.0);

		// Criando um assistente técnico sem bonus de salário
		Tecnico aTecnicoCoitado = new Tecnico("Assistente técnico", 3500.0, "1234AT", 0.0);

		// Criando um assistente técnico com adicional noturno
		Administrativo aAdm = new Administrativo("Assistente adm", 3500.0, "123AA", false, 450.0);

		// Criando um assistente técnico sem adicional noturno
		Administrativo aAdmCoitado = new Administrativo("Assistente adm", 3500.0, "123AA", true, 0.0);

		System.out.println(base + "\n");
		System.out.println(assistenteBase + "\n");
		System.out.println(aTecnico + "\n");
		System.out.println(aTecnicoCoitado + "\n");
		System.out.println(aAdm + "\n");
		System.out.println(aAdmCoitado + "\n");

		System.out.println("Alguns funcionários tiveram aumento:\n");
		assistenteBase.aumentarSalario(500.);
		aTecnicoCoitado.aumentarSalario(750.0);
		aAdm.aumentarSalario(850);
		aAdmCoitado.aumentarSalario(850.0);

		System.out.println(assistenteBase + "\n");
		System.out.println(aTecnicoCoitado + "\n");
		System.out.println(aAdm + "\n");
		System.out.println(aAdmCoitado + "\n");

	}
}
