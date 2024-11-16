// src/components/AuthForm.js
import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import '../styles/AuthForm.css';

function AuthForm({ onLogin }) {
    const [username, setUsername] = useState('');
    const [password, setPassword] = useState('');
    const [error, setError] = useState(null);
    const navigate = useNavigate();

    const handleLogin = async (e) => {
        e.preventDefault();
        try {
            const response = await fetch('http://localhost:5050/login', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ username, password }),
            });

            if (response.ok) {
                const token = await response.text();
                onLogin(token);
                navigate('/search');
            } else {
                setError('Credenciales incorrectas');
            }
        } catch (error) {
            setError('Error de conexión');
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
