﻿//
// Copyright (c) .NET Foundation and Contributors
// See LICENSE file in the project root for full license information.
//

using System.Collections.Generic;
using CommandLine;

namespace nanoFramework.nanoCLR.CLI
{
    [Verb("run", HelpText = "Run nanoCLR assembly.")]
    public class RunCommandLineOptions
    {
        public const string DefaultComPort = "COM3";

        [Option('l', "load", Required = false, HelpText = "Loads list of assemblies formatted for nanoCLR")]
        public IEnumerable<string> Assemblies { get; set; }

        //[Option('b', "loadDatabase", Required = false, HelpText = "Loads a set of assemblies")]
        //public string AssembliesSet { get; set; }

        [Option('s', "serialport", Required = false, HelpText = "Serial COM port to setup for debug connection")]
        public string DebugSerialPort { get; set; }

        [Option('p', "networkport", Required = false, HelpText = "Set TCP/IP port for incoming debug connection")]
        public int? DebugTcpIpPort { get; set; }

        [Option('n', "namedpipe", Required = false, HelpText = "Set Pipe Name for incoming debug connection")]
        public string DebugNamedPipe { get; set; }

        [Option('t', "traceWire", Required = false, HelpText = "Trace wire data packets")]
        public bool TraceWire { get; set; }

        [Option('r', "resolve", Required = false, HelpText = "Tries to resolve cross-assembly references")]
        public bool TryResolve { get; set; }

        /// <summary>
        /// Allowed values:
        /// q[uiet]
        /// m[inimal]
        /// n[ormal]
        /// d[etailed]
        /// diag[nostic]
        /// </summary>
        [Option(
            'v',
            "verbosity",
            Required = false,
            Default = "d",
            HelpText = "Sets the verbosity level of the command. Allowed values are q[uiet], m[inimal], n[ormal], d[etailed], and diag[nostic]. Not supported in every command; see specific command page to determine if this option is available.")]
        public string Verbosity { get; set; }
    }
}