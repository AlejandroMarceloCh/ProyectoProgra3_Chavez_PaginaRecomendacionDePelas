// App.js
import React, { useState, useEffect } from 'react';
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';
import HomePage from './pages/HomePage';
import SearchPage from './pages/SearchPage';
import AuthForm from './components/AuthForm';
import './styles/App.css';

function App() {
    const [isAuthenticated, setIsAuthenticated] = useState(false);

    useEffect(() => {
        const token = localStorage.getItem('authToken');
        if (token) {
            setIsAuthenticated(true);
        }
    }, []);

    const handleLogin = (token) => {
        localStorage.setItem('authToken', token);
        setIsAuthenticated(true);
    };

    const handleLogout = () => {
        localStorage.removeItem('authToken');
        setIsAuthenticated(false);
    };

    return (
        <Router>
            <div className="App container">
                {isAuthenticated && <h2></h2>} {/* Mostrar solo si está autenticado */}
                <Routes>
                    <Route path="/" element={isAuthenticated ? <Navigate to="/search" /> : <Navigate to="/login" />} />
                    <Route path="/login" element={<AuthForm onLogin={handleLogin} />} />
                    <Route path="/search" element={isAuthenticated ? <SearchPage onLogout={handleLogout} /> : <Navigate to="/login" />} />
                    <Route path="/home" element={<HomePage />} />
                </Routes>
            </div>
        </Router>
    );
}

export default App;
