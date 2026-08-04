# BE-03: Supabase Auth with FastAPI (Week 4 Assignment A4)

This project implements a secure backend API built with **FastAPI** and integrated with **Supabase Auth** as the identity provider. It supports user sign-up, login, token-protected routes, and logout functionality.

## Features
- **User Authentication**: Sign Up and Log In endpoints powered by Supabase.
- **Route Guarding**: A reusable FastAPI dependency that extracts and validates JWT bearer tokens.
- **API Documentation**: Fully interactive Swagger UI available at `/docs` with a global **Authorize** padlock button to test protected routes.
- **Strict Error Handling**: Custom error formatter returning error details in the required `{"error": "message"}` format.

---

## Setup Instructions

### 1. Prerequisites
Ensure you have Python 3.10+ installed.

### 2. Install Dependencies
Activate your virtual environment and install the required packages:

```bash
pip install -r requirements.txt
```

### 3. Environment Variables Setup
Copy the template `.env.example` file to create your own `.env` file:

```bash
cp .env.example .env
```

Open `.env` and fill in your Supabase project credentials (retrieved from **Project Settings → API** in the Supabase Dashboard):
- `SUPABASE_URL`: Your Project URL.
- `SUPABASE_KEY`: Your project's `anon` (public) key.
- `PORT`: Set your preferred local port (default is `3000`).

---

## Running the Server

Start the API server locally using the following command:

```bash
uvicorn main:app --reload --port 3000
```

*The API will be available at http://127.0.0.1:3000. Interactive Swagger docs can be accessed at http://127.0.0.1:3000/docs.*

---

## API Reference

The server exposes 5 main endpoints:

| Endpoint | Method | Authentication | Request Body (JSON) | Success Code | Error Codes / Scenarios |
|---|---|---|---|---|---|
| `/auth/signup` | POST | None | `{"email": "...", "password": "..."}` | `201 Created` | `400` (missing/empty fields), `500` (Supabase signup error) |
| `/auth/login` | POST | None | `{"email": "...", "password": "..."}` | `200 OK` | `400` (missing/empty fields), `401` (invalid login credentials) |
| `/auth/logout` | POST | Bearer Token | None | `204 No Content` | `401` (missing/expired token) |
| `/protected/profile`| GET | Bearer Token | None | `200 OK` | `401` (missing/expired token) |
| `/public/info` | GET | None | None | `200 OK` | N/A |

---

## Testing Protected Routes via Swagger `/docs`
1. Run the server and navigate to `http://localhost:3000/docs`.
2. Use the `/auth/login` endpoint to log in with an existing user. Copy the `access_token` from the response.
3. Click the global **Authorize** button in the top-right corner.
4. Enter your token in the input box and click **Authorize**.
5. You can now use "Try it out" on any of the protected endpoints (e.g., `/protected/profile`) directly in the browser.
