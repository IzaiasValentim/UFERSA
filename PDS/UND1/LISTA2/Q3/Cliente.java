
import java.util.List;

public class Cliente {
	private String nome;
	private String cpf;
	private String telefone;
	private int idade;
	private List<Locacao> locacoes;

	public Cliente(String nome, String cpf, String telefone, int idade) {
		this.nome = nome;
		this.cpf = cpf;
		this.telefone = telefone;
		this.idade = idade;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public List<Locacao> getLocacoes() {
		return locacoes;
	}

	public void setLocacoes(Locacao loc) {
		this.locacoes.add(loc);
	}

}
