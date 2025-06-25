package Q8;

import java.util.ArrayList;
import java.util.List;

// Componente (Interface)
interface ElementoGrafico {
    void exibir();
    void mover(int x, int y);
}

// Folha (Componentes Concretos)
class Circulo implements ElementoGrafico {
    private String nome;
    private int x, y; // Posição
    private double raio;

    public Circulo(String nome, int x, int y, double raio) {
        this.nome = nome;
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    @Override
    public void exibir() {
        System.out.println("  Exibindo Círculo '" + nome + "' na posição (" + x + "," + y + ") com raio " + raio);
    }

    @Override
    public void mover(int dx, int dy) {
        this.x += dx;
        this.y += dy;
        System.out.println("  Movendo Círculo '" + nome + "' para (" + x + "," + y + ")");
    }
}

class Quadrado implements ElementoGrafico {
    private String nome;
    private int x, y; // Posição do canto superior esquerdo
    private double lado;

    public Quadrado(String nome, int x, int y, double lado) {
        this.nome = nome;
        this.x = x;
        this.y = y;
        this.lado = lado;
    }

    @Override
    public void exibir() {
        System.out.println("  Exibindo Quadrado '" + nome + "' na posição (" + x + "," + y + ") com lado " + lado);
    }

    @Override
    public void mover(int dx, int dy) {
        this.x += dx;
        this.y += dy;
        System.out.println("  Movendo Quadrado '" + nome + "' para (" + x + "," + y + ")");
    }
}

// Composite (Componente Concreto)
class GrupoDeFormas implements ElementoGrafico {
    private String nome;
    private List<ElementoGrafico> elementos = new ArrayList<>();

    public GrupoDeFormas(String nome) {
        this.nome = nome;
    }

    public void adicionar(ElementoGrafico elemento) {
        elementos.add(elemento);
        System.out.println("  Adicionado " + elemento.getClass().getSimpleName() + " ao Grupo '" + nome + "'");
    }

    public void remover(ElementoGrafico elemento) {
        elementos.remove(elemento);
        System.out.println("  Removido " + elemento.getClass().getSimpleName() + " do Grupo '" + nome + "'");
    }

    @Override
    public void exibir() {
        System.out.println("Exibindo Grupo '" + nome + "':");
        for (ElementoGrafico elemento : elementos) {
            elemento.exibir(); // Delega a exibição para cada elemento filho
        }
    }

    @Override
    public void mover(int dx, int dy) {
        System.out.println("Movendo Grupo '" + nome + "' por (" + dx + "," + dy + "):");
        for (ElementoGrafico elemento : elementos) {
            elemento.mover(dx, dy); // Delega o movimento para cada elemento filho
        }
    }
}
