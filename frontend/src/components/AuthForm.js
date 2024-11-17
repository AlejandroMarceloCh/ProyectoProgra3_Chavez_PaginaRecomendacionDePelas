import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { login } from '../api/auth'; // Cambiado para usar `login` de la API
import '../styles/AuthForm.css';

function AuthForm({ onLogin }) {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const [error, setError] = useState(null);
  const navigate = useNavigate();

  const handleLogin = async (e) => {
    e.preventDefault();
    try {
      const response = await login(username, password);
      localStorage.setItem('username', username);
      onLogin(username);
      navigate('/search');
    } catch (error) {
      setError(error.message);
    }
  };

  return (
    <div className="auth-page">
      <div className="auth-overlay">
        <div className="auth-content">
          <h1 className="auth-title">Bienvenido</h1>
          <p className="auth-subtitle">Ingresa tu usuario y accede al contenido ilimitado</p>
          <div className="auth-form">
            {error && <p className="error">{error}</p>}
            <form onSubmit={handleLogin}>
              <input
                type="text"
                placeholder="Usuario"
                value={username}
                onChange={(e) => setUsername(e.target.value)}
                required
              />
              <input
                type="password"
                placeholder="Contraseña"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                required
              />
              <button className="login-button" type="submit">Entrar</button>
            </form>
          </div>
        </div>
      </div>
    </div>
  );
}

export default AuthForm;
