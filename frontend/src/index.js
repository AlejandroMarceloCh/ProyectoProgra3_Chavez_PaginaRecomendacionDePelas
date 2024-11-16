// src/index.js
import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
//import './styles/index.css'; // Archivo CSS principal para estilos globales

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <React.StrictMode>
        <App />
    </React.StrictMode>
);
