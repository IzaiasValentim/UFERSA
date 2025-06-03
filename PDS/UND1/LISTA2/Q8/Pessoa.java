public class Pessoa {
    private String nome;
    private String email;

    public Pessoa(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    // Métodos Getters (Encapsulamento)
    public String getNome() {
        return nome;
    }

    public String getEmail() {
        return email;
    }

    // Métodos Setters (Encapsulamento)
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void exibirInformacoes() {
        System.out.println("Nome: " + this.nome + ", Email: " + this.email);
    }
}