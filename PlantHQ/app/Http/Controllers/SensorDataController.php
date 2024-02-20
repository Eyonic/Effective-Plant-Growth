<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class SensorDataController extends Controller
{


    public function index()
{
    $sensorData = SensorData::all();
    return view('home', compact('sensorData'));
}




    public function store(Request $request)
    {
        $request->validate([
            'name' => 'required|string|max:255',
            'moisture' => 'required|integer',
            'light' => 'required|integer',
        ]);

        $sensorData = SensorData::create([
            'name' => $request->name,
            'moisture' => $request->moisture,
            'light' => $request->light,
        ]);

        return response()->json($sensorData, 201);
    }
}
