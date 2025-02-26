
public class Main{
	public static void main(String[] args) {
		Time patos = new Time("TeamPatos", "Qua", "Lagoa dos Cisnes", 5, "Avinauricos", 0, 0, 0, "QUA-1");
		
		System.out.println("O time foi cadastrado com sucesso? " + patos.validarCadastro());

		patos.dadosDoTime();

		patos.computarVitoria();
		patos.computarEmpate();

		patos.situacaoDoTime();
	}
}