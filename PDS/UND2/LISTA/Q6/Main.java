package Q6;

import java.util.ArrayList;
import java.util.List;

// Observador (Interface)
interface Monitor {
    void atualizar(double dado);
}

// Sujeito (Interface/Classe Abstrata)
abstract class SensorDeDados {
    private List<Monitor> observadores = new ArrayList<>();

    public void adicionarObservador(Monitor observador) {
        observadores.add(observador);
        System.out.println("Observador adicionado.");
    }

    public void removerObservador(Monitor observador) {
        observadores.remove(observador);
        System.out.println("Observador removido.");
    }

    // Método para notificar todos os observadores
    protected void notificarObservadores(double dado) {
        for (Monitor observador : observadores) {
            observador.atualizar(dado);
        }
    }

    // Método para simular a leitura de dados do sensor
    public abstract void lerDados();
}

// Sujeito Concreto
class SensorDeTemperatura extends SensorDeDados {
    private double temperaturaAtual;

    public void setTemperatura(double temperatura) {
        this.temperaturaAtual = temperatura;
        // Quando a temperatura muda, notificamos os observadores
        System.out.println("\nSensor de Temperatura: Nova leitura - " + temperatura + "°C");
        notificarObservadores(temperaturaAtual);
    }

    @Override
    public void lerDados() {
        // Simula a leitura de um novo dado
        double novaTemperatura = 20.0 + Math.random() * 5; // Variação aleatória
        setTemperatura(novaTemperatura);
    }
}

// Observadores Concretos
class DisplayDeVisualizacao implements Monitor {
    private String nome;

    public DisplayDeVisualizacao(String nome) {
        this.nome = nome;
    }

    @Override
    public void atualizar(double dado) {
        System.out.println(nome + ": Exibindo nova temperatura: " + String.format("%.2f", dado) + "°C");
    }
}

class SistemaDeAlarme implements Monitor {
    private double limiteAlerta;

    public SistemaDeAlarme(double limiteAlerta) {
        this.limiteAlerta = limiteAlerta;
    }

    @Override
    public void atualizar(double dado) {
        if (dado > limiteAlerta) {
            System.out.println("!!! ALARME !!! Temperatura alta detectada: " + String.format("%.2f", dado) + "°C");
        } else {
            System.out.println("Sistema de Alarme: Temperatura normal: " + String.format("%.2f", dado) + "°C");
        }
    }
}

class RegistradorDeDados implements Monitor {
    @Override
    public void atualizar(double dado) {
        System.out.println("Registrador de Dados: Registrando: " + String.format("%.2f", dado) + "°C no banco de dados.");
        // Lógica para salvar dado em DB/arquivo
    }
}

// Classe Cliente para demonstrar o sistema
class SistemaDeMonitoramentoAmbiental {
    public static void main(String[] args) {
        SensorDeTemperatura sensor = new SensorDeTemperatura();

        // Criando observadores
        Monitor display = new DisplayDeVisualizacao("Painel Principal");
        Monitor alarme = new SistemaDeAlarme(23.0);
        Monitor registrador = new RegistradorDeDados();

        // Adicionando observadores ao sensor
        sensor.adicionarObservador(display);
        sensor.adicionarObservador(alarme);
        sensor.adicionarObservador(registrador);

        // Simulando leituras do sensor
        sensor.lerDados(); // Primeira leitura
        sensor.lerDados(); // Segunda leitura
        sensor.lerDados(); // Terceira leitura

        // Removendo um observador
        sensor.removerObservador(display);

        // Nova leitura após remover um observador
        sensor.lerDados();
    }
}
