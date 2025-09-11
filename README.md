# Minitalk

Programme de communication inter-processus utilisant les signaux UNIX (SIGUSR1/SIGUSR2).

## Description

Minitalk permet d'envoyer des messages texte entre deux processus en utilisant uniquement des signaux. Le serveur reçoit et affiche les messages, le client les envoie caractère par caractère via transmission bit par bit.

## Compilation

```bash
make
```

## Utilisation

1. **Lancer le serveur :**
```bash
./server
```

2. **Envoyer un message :**
```bash
./client [PID_serveur] "Votre message"
```

### Exemple
```bash
# Terminal 1
./server
Pid Server : 12345

# Terminal 2
./client 12345 "Hello 42!"
```

---
**Projet 42**