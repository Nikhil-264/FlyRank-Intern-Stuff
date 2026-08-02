import React, { useState, useEffect } from 'react';
import { 
  Play, 
  Octagon, 
  Activity, 
  FileText, 
  User, 
  Layers, 
  Database,
  ArrowRight,
  TrendingDown,
  Settings,
  Shield,
  Wifi,
  WifiOff
} from 'lucide-react';

export default function App() {
  const [wsStatus, setWsStatus] = useState('connecting'); // connecting, open, closed
  const [machineState, setMachineState] = useState({
    state: 'idle',
    position: { x: 0.0, y: 0.0 },
    current_command: 'NONE',
    error_code: 0,
    error_message: ''
  });
  const [lockHolder, setLockHolder] = useState(null);
  const [logs, setLogs] = useState([
    { id: 1, timestamp: new Date(Date.now() - 5000).toLocaleTimeString(), position: "X: 0.0, Y: 0.0", event: "SYSTEM_INITIALIZED" },
    { id: 2, timestamp: new Date(Date.now() - 3000).toLocaleTimeString(), position: "X: 0.0, Y: 0.0", event: "STANDBY_READY" }
  ]);

  // Connect to the telemetry WebSocket
  useEffect(() => {
    let ws;
    const connectWS = () => {
      const wsUrl = import.meta.env.VITE_WS_URL || 'ws://localhost:8000/ws';
      console.log('Connecting to WebSocket:', wsUrl);
      ws = new WebSocket(wsUrl);
      
      ws.onopen = () => {
        setWsStatus('open');
      };
      
      ws.onmessage = (event) => {
        try {
          const data = JSON.parse(event.data);
          console.log('Telemetry received:', data);
          if (data.type === 'welcome' || data.type === 'telemetry') {
            setLockHolder(data.lock_holder);
            // If the backend has extended telemetry fields, update machineState
            if (data.state) {
              setMachineState({
                state: data.state,
                position: data.position || { x: 0.0, y: 0.0 },
                current_command: data.current_command || 'NONE',
                error_code: data.error_code || 0,
                error_message: data.error_message || ''
              });
            }
          }
        } catch (err) {
          console.error('Error parsing WS message:', err);
        }
      };

      ws.onclose = () => {
        setWsStatus('closed');
        setTimeout(connectWS, 3000); // Retry connection
      };

      ws.onerror = (err) => {
        console.error('WS Error:', err);
        ws.close();
      };
    };

    connectWS();
    return () => {
      if (ws) ws.close();
    };
  }, []);

  const handleEmergencyStop = async () => {
    try {
      const apiUrl = import.meta.env.VITE_API_URL || 'http://localhost:8000';
      const response = await fetch(`${apiUrl}/api/machine/stop`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' }
      });
      const data = await response.json();
      
      // Append emergency log
      const newLog = {
        id: Date.now(),
        timestamp: new Date().toLocaleTimeString(),
        position: `X: ${machineState.position.x}, Y: ${machineState.position.y}`,
        event: "EMERGENCY_STOP_TRIGGERED"
      };
      setLogs(prev => [newLog, ...prev]);
      alert(`Emergency Stop: ${data.message}`);
    } catch (err) {
      console.error('Error triggering E-stop:', err);
      alert('Failed to connect to API server to trigger E-stop.');
    }
  };

  return (
    <div className="min-h-screen bg-slate-950 text-slate-100 flex flex-col selection:bg-brand-500 selection:text-white relative overflow-hidden">
      
      {/* Background Glows */}
      <div className="absolute top-[-10%] left-[-10%] w-[50%] h-[50%] rounded-full bg-brand-900/10 blur-[120px] pointer-events-none" />
      <div className="absolute bottom-[-10%] right-[-10%] w-[50%] h-[50%] rounded-full bg-emerald-950/10 blur-[120px] pointer-events-none" />

      {/* HEADER */}
      <header className="border-b border-slate-900 bg-slate-950/80 backdrop-blur-md sticky top-0 z-50">
        <div className="max-w-7xl mx-auto px-6 py-4 flex items-center justify-between">
          <div className="flex items-center space-x-3">
            <div className="bg-brand-600/20 text-brand-400 p-2 rounded-xl border border-brand-500/20">
              <Layers className="w-6 h-6 animate-pulse" />
            </div>
            <div>
              <h1 className="font-bold text-lg tracking-tight bg-gradient-to-r from-white to-slate-400 bg-clip-text text-transparent">
                MTP Dip Coater
              </h1>
              <p className="text-xs text-slate-500 font-medium">Master's Thesis Control Hub</p>
            </div>
          </div>

          <div className="flex items-center space-x-4">
            {/* WS Status Badge */}
            <div className={`flex items-center space-x-2 px-3 py-1.5 rounded-full text-xs font-semibold border ${
              wsStatus === 'open' 
                ? 'bg-emerald-950/30 text-emerald-400 border-emerald-500/20' 
                : 'bg-rose-950/30 text-rose-400 border-rose-500/20'
            }`}>
              {wsStatus === 'open' ? (
                <>
                  <Wifi className="w-3.5 h-3.5" />
                  <span>Telemetry Live</span>
                </>
              ) : (
                <>
                  <WifiOff className="w-3.5 h-3.5" />
                  <span>Telemetry Reconnecting</span>
                </>
              )}
            </div>

            <div className="flex items-center space-x-2 bg-slate-900/80 border border-slate-800 px-3 py-1.5 rounded-xl">
              <User className="w-4 h-4 text-slate-400" />
              <span className="text-xs text-slate-300 font-medium">Guest (Offline Dev Mode)</span>
            </div>
          </div>
        </div>
      </header>

      {/* DASHBOARD GRID */}
      <main className="flex-1 max-w-7xl w-full mx-auto px-6 py-8 grid grid-cols-1 lg:grid-cols-12 gap-8 z-10">
        
        {/* LEFT COLUMN: Controls & telemetry */}
        <section className="lg:col-span-8 space-y-8">
          
          {/* Machine Telemetry Panel */}
          <div className="glass-panel rounded-3xl p-8 relative overflow-hidden">
            <div className="flex justify-between items-center mb-6">
              <div className="flex items-center space-x-2.5">
                <Activity className="text-brand-400 w-5 h-5" />
                <h2 className="font-semibold text-base">Live Machine Telemetry</h2>
              </div>
              <span className="text-xs font-mono text-slate-500">GRBL Controller Interface</span>
            </div>

            <div className="grid grid-cols-1 md:grid-cols-3 gap-6">
              {/* Coordinates */}
              <div className="bg-slate-900/40 border border-slate-900 p-6 rounded-2xl flex flex-col justify-between">
                <span className="text-xs text-slate-500 uppercase tracking-wider font-semibold">X-Axis Carriage</span>
                <div className="my-2">
                  <span className="text-4xl font-extrabold font-mono tracking-tight text-white">
                    {machineState.position.x.toFixed(2)}
                  </span>
                  <span className="text-slate-500 text-sm ml-1">mm</span>
                </div>
                <div className="w-full bg-slate-800 h-1.5 rounded-full overflow-hidden">
                  <div 
                    className="bg-brand-500 h-full transition-all duration-300"
                    style={{ width: `${Math.min(100, Math.max(0, (machineState.position.x / 300) * 100))}%` }}
                  />
                </div>
              </div>

              <div className="bg-slate-900/40 border border-slate-900 p-6 rounded-2xl flex flex-col justify-between">
                <span className="text-xs text-slate-500 uppercase tracking-wider font-semibold">Y-Axis (Dipper)</span>
                <div className="my-2">
                  <span className="text-4xl font-extrabold font-mono tracking-tight text-white">
                    {machineState.position.y.toFixed(2)}
                  </span>
                  <span className="text-slate-500 text-sm ml-1">mm</span>
                </div>
                <div className="w-full bg-slate-800 h-1.5 rounded-full overflow-hidden">
                  <div 
                    className="bg-emerald-500 h-full transition-all duration-300"
                    style={{ width: `${Math.min(100, Math.max(0, (Math.abs(machineState.position.y) / 100) * 100))}%` }}
                  />
                </div>
              </div>

              {/* Status & Command */}
              <div className="bg-slate-900/40 border border-slate-900 p-6 rounded-2xl flex flex-col justify-between">
                <div>
                  <span className="text-xs text-slate-500 uppercase tracking-wider font-semibold block">Execution State</span>
                  <div className="flex items-center space-x-2 mt-2">
                    <span className={`w-2.5 h-2.5 rounded-full ${
                      machineState.state === 'idle' ? 'bg-emerald-500' :
                      machineState.state === 'error' ? 'bg-rose-500' : 'bg-amber-500 animate-ping'
                    }`} />
                    <span className="text-lg font-bold capitalize text-white">{machineState.state}</span>
                  </div>
                </div>
                <div className="mt-4 pt-4 border-t border-slate-900 flex justify-between items-center text-xs text-slate-400">
                  <span>Cmd: <code className="font-mono text-brand-400">{machineState.current_command}</code></span>
                  <span>Err: <code className="font-mono text-rose-400">{machineState.error_code}</code></span>
                </div>
              </div>
            </div>

            {/* Lock / Holder details */}
            <div className="mt-6 p-4 rounded-xl bg-slate-900/60 border border-slate-900 flex items-center justify-between text-xs text-slate-400">
              <div className="flex items-center space-x-2">
                <Shield className="w-4 h-4 text-brand-400" />
                <span>
                  {lockHolder 
                    ? `Machine locked by Job #${lockHolder.job_id} (User ID: ${lockHolder.user_id})` 
                    : "Machine Status: Free / Idle. Ready for jobs."
                  }
                </span>
              </div>
              <div className="flex space-x-2">
                <button 
                  onClick={handleEmergencyStop} 
                  className="bg-rose-600 hover:bg-rose-700 text-white font-bold px-4 py-2 rounded-lg flex items-center space-x-1.5 transition-all text-xs shadow-lg shadow-rose-950/20 active:scale-95"
                >
                  <Octagon className="w-3.5 h-3.5" />
                  <span>EMERGENCY STOP</span>
                </button>
              </div>
            </div>
          </div>

          {/* Dummy Recipe Creator / Job Launch Panel */}
          <div className="glass-panel rounded-3xl p-8">
            <div className="flex items-center space-x-2.5 mb-6">
              <FileText className="text-brand-400 w-5 h-5" />
              <h2 className="font-semibold text-base">Interactive Recipe Sandbox</h2>
            </div>
            
            <div className="bg-slate-900/30 border border-slate-900 p-6 rounded-2xl space-y-4">
              <h3 className="text-sm font-medium text-slate-300">Phase 1 CRUD & Auth Verification</h3>
              <p className="text-xs text-slate-400">
                You can create recipes via SQL endpoints. This form represents the schema structure of a Dip Coater recipe. In future phases, these inputs will schedule real jobs.
              </p>
              
              <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
                <div>
                  <label className="block text-xs font-semibold text-slate-500 uppercase tracking-wider mb-2">Recipe Name</label>
                  <input type="text" defaultValue="Gold Nano-assembly (10-layers)" className="w-full bg-slate-950 border border-slate-800 rounded-xl px-4 py-2.5 text-sm focus:outline-none focus:border-brand-500 text-slate-200" />
                </div>
                <div>
                  <label className="block text-xs font-semibold text-slate-500 uppercase tracking-wider mb-2">Cycles</label>
                  <input type="number" defaultValue="5" className="w-full bg-slate-950 border border-slate-800 rounded-xl px-4 py-2.5 text-sm focus:outline-none focus:border-brand-500 text-slate-200" />
                </div>
              </div>

              {/* Steps Mockup */}
              <div className="border border-slate-900 rounded-xl p-4 bg-slate-950/50 space-y-2">
                <span className="text-xs text-slate-500 font-semibold block uppercase">Dipper Sequence steps</span>
                <div className="flex items-center justify-between text-xs p-2 rounded bg-slate-900/60 border border-slate-800">
                  <span className="font-medium text-slate-300">Beaker #1</span>
                  <span>Depth: <code className="text-brand-400">50mm</code></span>
                  <span>Dwell: <code className="text-brand-400">10000ms</code></span>
                  <span>Speed: <code className="text-brand-400">2.5mm/s</code></span>
                </div>
                <div className="flex items-center justify-between text-xs p-2 rounded bg-slate-900/60 border border-slate-800">
                  <span className="font-medium text-slate-300">Beaker #2</span>
                  <span>Depth: <code className="text-brand-400">30mm</code></span>
                  <span>Dwell: <code className="text-brand-400">5000ms</code></span>
                  <span>Speed: <code className="text-brand-400">5.0mm/s</code></span>
                </div>
              </div>

              <div className="flex justify-end pt-2">
                <button className="bg-brand-600 hover:bg-brand-500 text-white font-semibold text-xs px-5 py-2.5 rounded-xl flex items-center space-x-1.5 transition-all shadow-md shadow-brand-950/20 active:scale-95">
                  <span>Register Recipe API Dummy</span>
                  <ArrowRight className="w-3.5 h-3.5" />
                </button>
              </div>
            </div>
          </div>
        </section>

        {/* RIGHT COLUMN: Thesis logs / History */}
        <section className="lg:col-span-4 space-y-8">
          
          {/* Run Logs for Thesis Data */}
          <div className="glass-panel rounded-3xl p-6 flex flex-col h-full justify-between">
            <div>
              <div className="flex justify-between items-center mb-6">
                <div className="flex items-center space-x-2">
                  <Database className="text-brand-400 w-4 h-4" />
                  <h2 className="font-semibold text-sm">Thesis Run Logs (CSV Stream)</h2>
                </div>
                <span className="text-[10px] bg-slate-900 border border-slate-800 px-2 py-0.5 rounded font-mono text-emerald-400">SQL/TSDB</span>
              </div>

              <p className="text-xs text-slate-400 mb-4">
                These data points log actual hardware position coordinates, feeding directly into your thesis analysis.
              </p>

              {/* Logs Stream Container */}
              <div className="space-y-3 max-h-[360px] overflow-y-auto pr-1">
                {logs.map((log) => (
                  <div key={log.id} className="p-3 rounded-xl bg-slate-900/40 border border-slate-900 text-xs flex flex-col space-y-1 relative">
                    <div className="flex justify-between items-center text-[10px]">
                      <span className="text-slate-500 font-mono">{log.timestamp}</span>
                      <span className="text-slate-400 font-medium font-mono">{log.position}</span>
                    </div>
                    <span className="font-semibold text-slate-200 tracking-wide font-mono break-all">{log.event}</span>
                  </div>
                ))}
              </div>
            </div>

            <div className="mt-6 pt-4 border-t border-slate-900">
              <button 
                onClick={() => {
                  alert("CSV export will compile database logs from models.RunLog into a comma-separated-value format.");
                }} 
                className="w-full bg-slate-900 hover:bg-slate-800 text-slate-300 font-semibold text-xs py-3 rounded-xl border border-slate-800 transition-all flex items-center justify-center space-x-2"
              >
                <span>Export Run logs to CSV</span>
              </button>
            </div>
          </div>
        </section>

      </main>

      {/* FOOTER */}
      <footer className="border-t border-slate-900 py-6 bg-slate-950 mt-12">
        <div className="max-w-7xl mx-auto px-6 flex justify-between items-center text-xs text-slate-600 font-medium">
          <span>Dip Coater Control App (Thesis Phase 1 Scaffold)</span>
          <span className="flex items-center space-x-1.5">
            <span className="w-1.5 h-1.5 rounded-full bg-brand-500" />
            <span>Ready for Hardware Hookups</span>
          </span>
        </div>
      </footer>
    </div>
  );
}
