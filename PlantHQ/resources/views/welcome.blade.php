<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sensor Data</title>
    <!-- Bootstrap CSS -->
    <link href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {
            padding: 20px;
        }
        .table-container {
            animation: fadeInAnimation ease 2s;
            animation-iteration-count: 1;
            animation-fill-mode: forwards;
        }
        @keyframes fadeInAnimation {
            0% {
                opacity: 0;
                transform: translateY(20px);
            }
            100% {
                opacity: 1;
                transform: translateY(0);
            }
        }
        h1 {
            text-align: center;
            margin-bottom: 40px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Sensor Data</h1>
        <div class="table-responsive table-container">
            <table class="table table-bordered table-hover">
                <thead class="thead-dark">
                    <tr>
                        <th>Name</th>
                        <th>Moisture</th>
                        <th>Light</th>
                        <th>Timestamp</th>
                    </tr>
                </thead>
                <tbody>
                    @foreach ($sensorData as $data)
                        <tr>
                            <td>{{ $data->name }}</td>
                            <td>{{ $data->moisture }}</td>
                            <td>{{ $data->light }}</td>
                            <td>{{ $data->created_at->toFormattedDateString() }}</td>
                        </tr>
                    @endforeach
                </tbody>
            </table>
        </div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.5.2/dist/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</body>
</html>
